#!/usr/bin/env python
# coding: utf-8

# In[33]:


art='''
  __   _,_ /)  /)  _   _      /_   _,_      ,    _ 
_(_,__(_/_//__//__(/__(/_   _/ (__(_/_(_/__/_)__(/_  ☕
        _/  _/                                     
        /)  /)                                     
        `   `                                      
'''

menu={'espresso':{'ingredients':{'water':50,'coffee':18,'milk':0},'cost':1.5}, 
      'latte':{'ingredients':{'water':200,'coffee':24,'milk':150},'cost':2.5}, 
      'cappuccino':{'ingredients':{'water':250,'coffee':24,'milk':100},'cost':3.0}}

res={'water':500,'coffee':100,'milk':300}

profit=0

def report():
    for x in res:
        print(x.title(),':', res[x])
    print("Money : $",profit)
        
def pay(v):
    global profit
    tot=int(input("How many pennies: "))*.01
    tot+=int(input("How many nickels: "))*.05
    tot+=int(input("How many dimes: "))*.1
    tot+=int(input("How many quarters: "))*.25
    if tot<v:
        print("Insufficent amount. Money refunded.") # Pay again.")
        #pay(v)
        return False
    else:
        print("Collect your change $%.2f" %(tot-v))
        profit+=v
        return True
    
def make(item):
    for i in menu[item]['ingredients']:
        if res[i]<menu[item]['ingredients'][i]:
            print(f"Sorry {i} not available :(\nTry again later!")
            return 'off'
    print(f"\nMaking your drink ☕ :)\nPlease pay ${menu[item]['cost']}")
    amt=pay(menu[item]['cost'])
    if amt:
        for i in menu[item]['ingredients']:
            res[i]-=menu[item]['ingredients'][i]
    print(f"Enjoy your {item} ☕ :)\nHave a nice day")
    return 'on'
    
print(art)
print("Welcome to Coffee House☕")
status='on'
while status=='on':
    ip=input("\nWhat would you like to have (espresso/ latte/ cappuccino/ report)? :").lower()
    if ip=='report':
        report()
    elif ip=='off':
        status='off'
    else:
        status=make(ip)


# In[ ]:




