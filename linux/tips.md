## Some Notes
#### <ins>1. Install packages apt Offline<ins>
```sh
docker run -it -d --network=host -v /absolute_path/to/som_folder:/var/cache/apt/archives --name download_packages ubuntu:18.04
```
Execute to `download_packages` container:
```sh
docker exec -it download_packages bash
```
Download all packages with command:
```sh
apt-get update && apt-get install -d package_name
```
Install packages in new machine:
```sh
apt install ./*.deb
```
#### <ins>2. Dockefile and Setup sample<ins>
Add to ~/.bashrc
```sh
function enter() {
    local container_id="$1"
    docker exec -it $container_id /bin/bash
}

function hotload() {
    local services="$@"
    docker-compose kill $services && \
    docker-compose up -d --no-deps --force-recreate $services && \
    docker-compose logs -f $services
}

function hotbuild() {
    local services="$@"
    docker-compose kill $services && \
    docker-compose up -d --no-deps --build $services && \
    docker-compose logs -f $services
}
```

```sh
ARG BASE_IMAGE
FROM ${BASE_IMAGE}


WORKDIR /app

    # install python requirements
    ADD docker_sets/voice2text/core/master/requirements.txt .
    RUN pip install \
            -i http://hanoi_packages.pypi:8080/simple/ \
            --trusted-host hanoi_packages.pypi \
            -r requirements.txt

    ADD docker_sets/voice2text/core/master/ /app
    ADD diarization_v2/expand_timeslices-wiser.py /app/utils/expand_timeslices_wiser.py

    ADD utils_v2/common.sh /opt/utils_v2/common.sh

    CMD ["/bin/bash", "run.sh"]
```