# Unlock id bluetooth card is locked (password requested)
if [[ $(rfkill -r | grep 'wlan phy0 blocked') = *wlan\ phy0\ blocked* ]]; then
  sudo rfkill unblock wlan
  echo "Wlan unlocked"
fi
