while true;
do
	wget -O /home/marco/Documents/Pictures/picsum_${RANDOM%10000}.jpg "https://picsum.photos/1080/1320.jpg"
# not blured picture
# "https://picsum.photos/1080/1320.jpg"

# blured picture
#"https://picsum.photos/1080/1320?blur=${RANDOM:0:1}.jpg"
done

