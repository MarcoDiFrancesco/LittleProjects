![Description](https://i.imgur.com/0qJqKnu.png)
![Description2](https://i.imgur.com/7I1UNZD.png)
``` c++
getFounds(founds[], int n) {
  float minMax = +inf // Max minimum of the 2 vinici
  float maxVicini[n]
  for(int i = 1; i < n-1; i++) {
    if(founds[i-1] + founds[i+1] < minMax) {
      minMax = i;
    }
  }
  for(int i = 0; i < n; i++) {
    int a = 0;
    if(i != minMax - 1 && i != minMax + 1){
      maxVicini[a] = founds[i]
    }
  }
  return maxVicini[]
}
```