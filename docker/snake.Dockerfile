FROM ubuntu:20.04

ENV DEBIAN_FRONTEND noninteractive

# Install package dependencies
RUN apt-get update && apt-get install -y --no-install-recommends \
        build-essential \
        cmake \
        unzip \
        libncurses-dev \
        libsndfile-dev \
        libasound2-dev \
        sudo
RUN apt-get clean
