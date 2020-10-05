hours <- 3+1+1+2+0+0+2+0+2+2+0+1+2
mins <- 32+47+47+03+39+50+33+39+47+28+30+30+16

comp_hour <- 2+0
comp_mins <- 48+58

time <- (hours-comp_hour)*60 + mins-comp_mins

print(time/60)
