brightness=$(xbacklight -get)

# Get increase (-i) or decrease (-d)
while getopts 'id' flag
do
  case "${flag}" in
    i)
      case "$brightness" in
        [0-5])
          brightness=$((brightness+1))
        ;;
        [6-9])
          brightness=$((brightness+3))
        ;;
        [1]*)
          brightness=$((brightness+5))
        ;;
        [2-6]*)
          brightness=$((brightness+10))
        ;;
        [6-9]*)
          brightness=$((brightness+20))
        ;;
        *)
          echo 'Brightness increase error'
        ;;
      esac
    ;;
    d)
      case "$brightness" in
        1)
          echo 'Too low' 
        ;;
        [2-5])
          brightness=$((brightness-1))
        ;;
        [6-9])
          brightness=$((brightness-3))
        ;;
        [1]*)
          brightness=$((brightness-5))
        ;;
        [2-6]*)
          brightness=$((brightness-10))
        ;;
        [6-9]*)
          brightness=$((brightness-20))
        ;;
        *)
          echo 'Brightness increase error'
        ;;
    esac
    ;;
  esac
done

# 100ms of fading in 10 steps
xbacklight -set $brightness -time 100 -steps 10
echo 'Brightness set to '$brightness'%'