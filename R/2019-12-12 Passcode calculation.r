# A smartphone uses a four-digit passcode, like 0131.
# We want to reset the passcode such that the new passcode cannot have the digit 1 followed by the digit 3.
# How many different passcodes can be formed?

numbers <- c(0,1,2,3,4,5,6,7,8,9)
counter = 0
for(n1 in numbers) {
  for(n2 in numbers) {
    for(n3 in numbers) {
      for(n4 in numbers) {
        if(
          !(n1 == 3 && n2 == 1) &&
          !(n2 == 3 && n3 == 1) &&
          !(n3 == 3 && n4 == 1)
        ) {
          print(paste(n1,n2,n3,n4))
          counter = counter + 1
        }
      }
    }
  }
}
print(counter)