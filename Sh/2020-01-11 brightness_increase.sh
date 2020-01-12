brightness=$(xbacklight -get)

case "$brightness" in
  [0-5])
    brightness=$((brightness+1))
    echo 'Increasing 1%'
  ;;
  [6-9])
    brightness=$((brightness+3))
    echo 'Increasing 3%'
  ;;
  [1]*)
    brightness=$((brightness+5))
    echo 'Increasing 5%'
  ;;
  [2-6]*)
    brightness=$((brightness+10))
    echo 'Increasing 10%'
  ;;
  [6-9]*)
    brightness=$((brightness+20))
    echo 'Increasing 20%'
  ;;
  *)
    echo $brightness
  ;;
esac

xbacklight -set $brightness -time 100 -steps 10
echo 'Brightness set to' $brightness'%'