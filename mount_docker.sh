docker run -it --rm --mount type=bind,source="$(pwd)"/workspace,target=/workspace --env-file ./docker.env xyzsam/gem5-aladdin
