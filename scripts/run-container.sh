#!/bin/bash
# Starts the dev container image with the host display. Build it first, from the repo root:
#   docker build -t conveysort_arm_image -f .devcontainer/Dockerfile .
# If not working, first do: sudo rm -rf /tmp/.docker.xauth

# Allow local root user to access the X server
xhost local:root

# Set up the X authority file
XAUTH=/tmp/.docker.xauth

# Run the Docker container with the specified environment variables and volume mounts
docker run -it \
    --name=conveysort_arm_container \
    --env="DISPLAY=$DISPLAY" \
    --env="QT_X11_NO_MITSHM=1" \
    --volume="/tmp/.X11-unix:/tmp/.X11-unix:rw" \
    --env="XAUTHORITY=$XAUTH" \
    --volume="$XAUTH:$XAUTH" \
    --net=host \
    --privileged \
    conveysort_arm_image \
    bash

echo "Done."
