import datetime as d
name=input("enter your name:")
age=input("enter your age:")
old=100-int(age)
x=d.datetime.now()
y=(x.year+old)
print("Hello",name,"you will be 100 year old in the year",y)
