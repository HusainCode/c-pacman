# official Ubuntu
FROM ubuntu:24.04

# Install dependencies
RUN apt-get update && apt-get install -y \
    build-essential \
    libsdl2-dev \
    libsdl2-image-dev \
    libsdl2-mixer-dev \
    libsdl2-ttf-dev \
    git \
    && rm -rf /var/lib/apt/lists/*

# Set workdir
WORKDIR /app

# Copy source code into the container
COPY . .

# Build the game
RUN gcc -o pacman \
    src/*.c \
    -Iinclude \
    -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf

# Run the game (SDL will expect display)
CMD ["./pacman"]
