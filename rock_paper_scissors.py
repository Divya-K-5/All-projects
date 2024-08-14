#!/usr/bin/env python
# coding: utf-8

# In[ ]:


r='''
    _______
---'   ____)
      (_____)
      (_____)
      (____)
---.__(___) 
'''

p='''
    _______
---'   ____)____
          ______)
          _______)
         _______)
---.__________)
'''

s='''
    _______
---'   ____)____
          ______)
       __________)
      (____)
---.__(___)
'''
l=[r,p,s]
ans='y'
art='''

( _\    /_ )
 \ _\  /_ / 
  \ _\/_ /_ _
  |_____/_/ /|
  (  (_)__)J-)
  (  /`.,   /
   \/  ;   /
    | === |

'''
while(ans=='y'):
    for i in range(3):
        print("Choose: 0-Rock\t1-Paper\t2-Scissors")
        u=int(input())
        print("You:",l[u])
        c=randint(0,2)
        print("Computer:",l[c])
        user=comp=0
        if (u==0 and c==1) or (u==1 and c==2) or (u==2 and c==0):
            comp+=1
            print("\nOne point for computer!\n")
        elif (u==0 and c==0) or (u==1 and c==1) or (u==2 and c==2):
            print("Tie. No point =(\n")
        else:
            user+=1
            print("One point for user!\n")

    if user==comp:
        print("\nTie Match!!!\n")
    elif user>comp:
        print("\nYou Won!!!\n")
    else:
        print("\nComputer Won!!!\n")
    print("Do you want to continue? (y/n)")
    ans=input()
    

