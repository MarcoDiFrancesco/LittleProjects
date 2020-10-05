# Docker

Here there are all the tests I've done for docker.
The tests that have been useful have been uploaded in the main repository
[DockerTools](https://github.com/MarcoDiFrancesco/DockerTools).

## Docker commands

Build image

``` Docker
docker image build -t bulletinboard:1.0 /dir
```

Run container

``` Docker
docker container run --publish 8000:8080 --detach --name testBuild test:1.0
```
