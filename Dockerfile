FROM ubuntu:20.04

RUN apt-get update && apt-get upgrade && apt-get install -y \
    xz-utils \
    curl \
    make \
    clang-12 \
    freeglut3-dev \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /app

ENV DISPLAY=host.docker.internal:0.0

COPY . .

CMD ["bin/Connect4"]
