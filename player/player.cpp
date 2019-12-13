
#include <sndfile.h>
#include <cstring>
#include <iostream>

#include <alsa/asoundlib.h>

int main(int argc, char** argv) {

    //char filename[] = "ChillingMusic.wav";
    //char filename[] = "file_example_MP3_1MG.mp3";
    char filename[] = "BetterSounds.wav";

    const int out_channels = 2, out_samples = 512, sample_rate = 44100;

    SF_INFO sinfo;
    memset(&sinfo, 0, sizeof(sinfo));

    SNDFILE* sfile = sf_open(filename, SFM_READ, &sinfo);

    std::cout << sinfo.channels << std::endl;
    std::cout << sinfo.samplerate << std::endl;
    std::cout << sinfo.frames << std::endl;

    //float buffer[out_samples * out_channels] = {};
    //float buffer[10000000 * out_channels] = {};

    float* buffer = new float[sinfo.frames * out_channels];

    void* p = buffer;

    
    snd_pcm_t* pcm = NULL;
    snd_pcm_open(&pcm, "default", SND_PCM_STREAM_PLAYBACK, 0);
    // https://www.alsa-project.org/alsa-doc/alsa-lib/group___p_c_m.html#ga45d50841b307f2156fce1857bfac228c
    snd_pcm_set_params(pcm,
                           SND_PCM_FORMAT_FLOAT_LE,
                           SND_PCM_ACCESS_RW_INTERLEAVED,
                           out_channels,
                           sample_rate,
                           1,
                           sample_rate / 4);

    snd_pcm_uframes_t period_size = 0, buffer_size = 0;
    snd_pcm_get_params(pcm, &buffer_size, &period_size);
    std::cout << (long)period_size << " " << (long)buffer_size << " " << period_size * out_channels * sizeof(float) << std::endl;
    
    const int buf_sz = period_size * out_channels;

    sf_count_t ret = sf_readf_float(sfile, buffer, sinfo.frames);

    for (int i = 0; i < sinfo.frames * out_channels; i += buf_sz)
    {
        snd_pcm_writei(pcm, buffer + i, period_size);
    }


    sf_close(sfile);

    return 0;
}
