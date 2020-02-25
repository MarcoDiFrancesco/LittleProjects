#!/bin/bash

volume=$(pamixer --get-volume)

case "$volume" in
  [0-5])
    volume=$((volume+1))
    echo 'Increasing 1%'
  ;;
  [6-9])
    volume=$((volume+3))
    echo 'Increasing 3%'
  ;;
  [1]*)
    volume=$((volume+5))
    echo 'Increasing 5%'
  ;;
  [2-6]*)
    volume=$((volume+10))
    echo 'Increasing 10%'
  ;;
  [6-9]*)
    volume=$((volume+20))
    echo 'Increasing 20%'
  ;;
  *)
    echo $volume
  ;;
esac

# pactl set-sink-volume @DEFAULT_SINK@ -10%