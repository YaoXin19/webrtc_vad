
add_definitions(
    -DWEBRTC_POSIX
)

set(
    WEBRTC_SRC 

)

include_directories(

)

add_library(
    vad 
    STATIC
    ${WEBRTC_SRC}/modules/audio_processing/vad/standalone_vad.cc
    ${WEBRTC_SRC}/common_audio/vad/vad_core.c
    ${WEBRTC_SRC}/common_audio/vad/vad_filterbank.c
    ${WEBRTC_SRC}/common_audio/vad/vad_gmm.c
    ${WEBRTC_SRC}/common_audio/vad/vad_sp.c
    ${WEBRTC_SRC}/common_audio/vad/webrtc_vad.c
    ${WEBRTC_SRC}/common_audio/signal_processing/spl_init.c
    ${WEBRTC_SRC}/common_audio/signal_processing/spl_inl.c
    ${WEBRTC_SRC}/common_audio/signal_processing/spl_sqrt.c
    ${WEBRTC_SRC}/common_audio/signal_processing/splitting_filter.c
    ${WEBRTC_SRC}/common_audio/signal_processing/energy.c
    ${WEBRTC_SRC}/common_audio/signal_processing/get_scaling_square.c
    ${WEBRTC_SRC}/common_audio/signal_processing/resample_48khz.c
    ${WEBRTC_SRC}/common_audio/signal_processing/min_max_operations.c
    ${WEBRTC_SRC}/common_audio/signal_processing/vector_scaling_operations.c
    ${WEBRTC_SRC}/common_audio/signal_processing/cross_correlation.c
    ${WEBRTC_SRC}/common_audio/signal_processing/downsample_fast.c
    ${WEBRTC_SRC}/common_audio/signal_processing/division_operations.c
    ${WEBRTC_SRC}/common_audio/signal_processing/resample_fractional.c
    ${WEBRTC_SRC}/common_audio/signal_processing/resample_by_2_internal.c
)

add_executable(
    test
    test/test.cpp
)

target_link_libraries(
    test
    vad
    pthread
)