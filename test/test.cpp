#include "modules/audio_processing/vad/standalone_vad.h"

#include <cstdio>
#include <cassert>
#include <memory>

using namespace webrtc;

int main() {
	printf("===================================\n");

	std::unique_ptr<StandaloneVad> vad(StandaloneVad::Create());
	const size_t kDataLength = kLength10Ms;
	int16_t data[kDataLength] = { 0 };

	FILE* pcm_file = fopen("../resources/audio_processing/agc/agc_audio.pcm", "rb");
	if (!pcm_file)
		assert(false);

	FILE* reference_file = fopen("../resources/audio_processing/agc/agc_vad.dat", "rb");
	if (!reference_file)
		assert(false);

	vad->set_mode(0);

	const int kNumVadFramesToProcess = 3;
	int num_frames = 0;
	while (fread(data, sizeof(int16_t), kDataLength, pcm_file) == kDataLength) {
		vad->AddAudio(data, kDataLength);
		num_frames++;
		if (num_frames == kNumVadFramesToProcess) {
			num_frames = 0;
			int referece_activity;
			double p[kNumVadFramesToProcess];
			if (fread(&referece_activity, sizeof(referece_activity), 1, reference_file) != 1) {
				assert(false);
			}
			int activity = vad->GetActivity(p, kNumVadFramesToProcess);
			if (referece_activity != activity) {
				assert(false);
			}
			if (activity != 0) {
				// When active, probabilities are set to 0.5.
				for (int n = 0; n < kNumVadFramesToProcess; n++)
					printf("%f\n", p[n]);
			}
			else {
				// When inactive, probabilities are set to 0.01.
				for (int n = 0; n < kNumVadFramesToProcess; n++)
					printf("%f\n", p[n]);
			}
		}
	}
	fclose(reference_file);
	fclose(pcm_file);

	return 0;
}