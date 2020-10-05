# Currently not working 

#FROM ubuntu:18.04
FROM debian:sid

RUN echo 'debconf debconf/frontend select Noninteractive' | debconf-set-selections
WORKDIR /app
#COPY . .
RUN apt-get update
RUN apt-get install -y curl
RUN apt-get install -y iproute2
RUN apt-get install 
RUN curl -L https://install.pivpn.dev | bash

#CMD [ "npm", "start" ]
CMD /bin/bash