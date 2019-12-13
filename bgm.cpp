/* Decode audio file using libsndfile and write decoded samples to stdout.
 * Output format:
 *  - two channels (front left, front right)
 *  - samples in interleaved format (L R L R ...)
 *  - samples are 32-bit floats
 *  - sample rate is 44100
 *
 * Usage:
 *   ./sndfile_decode cool_song.wav > cool_song_samples
 */
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <sndfile.h>

int main(int argc, char** argv) {
    if (argc != 2) {
        fprintf(stderr, "usage: %s input_file > output_file\n", argv[0]);
        exit(1);
    }

    const int out_channels = 2, out_samples = 512, sample_rate = 44100;

    SF_INFO sinfo;
    memset(&sinfo, 0, sizeof(sinfo));

    SNDFILE* sfile = sf_open(argv[1], SFM_READ, &sinfo);
    if (!sfile) {
        fprintf(stderr, "sf_open()\n");
        exit(1);
    }

    if (sinfo.channels != out_channels) {
        fprintf(stderr, "unsupported # of channels\n");
        exit(1);
    }

    if (sinfo.samplerate != sample_rate) {
        fprintf(stderr, "unsupported sample rate\n");
        exit(1);
    }

    float buffer[out_samples * out_channels] = {};

    for (;;) {
        sf_count_t ret = sf_readf_float(sfile, buffer, 512);
        if (ret == 0) {
            break;
        }

        if (write(STDOUT_FILENO, buffer, sizeof(buffer)) != sizeof(buffer)) {
            fprintf(stderr, "write(stdout)\n");
            exit(1);
        }
    }

    sf_close(sfile);

    return 0;
}
