brightness=$(xbacklight -get)

case "$brightness" in
  1)
    echo 'Too low' 
  ;;
  [2-5])
    brightness=$((brightness-1))
    echo 'Decreasing 1%'
  ;;
  [6-9])
    brightness=$((brightness-3))
    echo 'Decreasing 3%'
  ;;
  [1]*)
    brightness=$((brightness-5))
    echo 'Decreasing 5%'
  ;;
  [2-6]*)
    brightness=$((brightness-10))
    echo 'Decreasing 10%'
  ;;
  [6-9]*)
    brightness=$((brightness-20))
    echo 'Decreasing 20%'
  ;;
  *)
    echo $brightness
  ;;
esac

xbacklight -set $brightness -time 100 -steps 10
echo 'Brightness set to' $brightness'%'