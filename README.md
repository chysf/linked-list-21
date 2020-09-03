# comp2012-assignment1
### Linked List for Mall, Shop and Product Objects

Test case 1:
Mall: HKUST Mall @ Clear Water Bay
Shops in HKUST Mall: nullptr
Mall: HKUST Super Mall @ Clearer Water Bay
Shops in HKUST Super Mall: (1,"Supermarket") -> nullptr
Shop: #1 Supermarket
printShop: No such shop.

Test case 2:
Shops in HKUST Mall: (1,"Supermarket A") -> (2,"Supermarket B") -> (3,"Supermarket C") -> nullptr
Remove result: true
Shops in HKUST Mall: (2,"Supermarket B") -> (3,"Supermarket C") -> nullptr
Shops in HKUST Original Mall: (1,"Supermarket A") -> (2,"Supermarket B") -> (3,"Supermarket C") -> nullptr

Test case 3:
Shops in HKUST Mall: (1,"Supermarket A") -> (2,"Supermarket B") -> (3,"Supermarket C") -> nullptr
Remove result: true
Shops in HKUST Mall: (1,"Supermarket A") -> (3,"Supermarket C") -> nullptr

Test case 4:
Shops in HKUST Mall: (1,"Supermarket A") -> (2,"Supermarket B") -> (3,"Supermarket C") -> nullptr
Remove result: true
Shops in HKUST Mall: (1,"Supermarket A") -> (2,"Supermarket B") -> nullptr

Test case 5:
Shops in HKUST Mall: (1,"Supermarket A") -> (2,"Supermarket B") -> (3,"Supermarket C") -> nullptr
Remove result: false
Shops in HKUST Mall: (1,"Supermarket A") -> (2,"Supermarket B") -> (3,"Supermarket C") -> nullptr

Test case 6:
Add result: true
Add result: false
Shops in HKUST Mall: (1,"Supermarket A") -> nullptr

Test case 7:
Products in Supermarket: none.
Products in Supermarket: ("XXBOX",3,2000,10) 
Products in Supermarket: ("XXBOX",3,2000,20) 
Products in Supermarket: ("XXBOX",3,2000,30) 

Test case 8:
Products in Supermarket: none.
Products in Supermarket: ("XXBOX",3,2000,10) 
Products in Supermarket: ("XXBOX",3,2000,10) ("YBOX",3,3000,40) 
Products in Supermarket: ("ZZZBOX",3,1000,20) ("XXBOX",3,2000,10) ("YBOX",3,3000,40) 
Products in Supermarket: ("Apple",0,5,200) ("ZZZBOX",3,1000,20) ("XXBOX",3,2000,10) ("YBOX",3,3000,40) 
Products in Supermarket: ("Apple",0,5,200) ("ZZZBOX",3,1000,20) ("XXBOX",3,2000,10) ("PreyStation",3,2500,37) ("YBOX",3,3000,40) 

Test case 9:
Products in Supermarket: ("Apple",0,5,200) ("ZZZBOX",3,1000,20) ("XXBOX",3,2000,10) ("PreyStation",3,2500,37) ("YBOX",3,3000,40) 
Remove result: false
Products in Supermarket: ("Apple",0,5,200) ("ZZZBOX",3,1000,20) ("XXBOX",3,2000,10) ("PreyStation",3,2500,37) ("YBOX",3,3000,40) 
Remove result: true
Products in Supermarket: ("Apple",0,5,100) ("ZZZBOX",3,1000,20) ("XXBOX",3,2000,10) ("PreyStation",3,2500,37) ("YBOX",3,3000,40) 
Remove result: false
Products in Supermarket: ("Apple",0,5,100) ("ZZZBOX",3,1000,20) ("XXBOX",3,2000,10) ("PreyStation",3,2500,37) ("YBOX",3,3000,40) 
Remove result: true
Products in Supermarket: ("ZZZBOX",3,1000,20) ("XXBOX",3,2000,10) ("PreyStation",3,2500,37) ("YBOX",3,3000,40) 
Remove result: true
Products in Supermarket: ("ZZZBOX",3,1000,20) ("PreyStation",3,2500,37) ("YBOX",3,3000,40) 
Remove result: true
Products in Supermarket: ("ZZZBOX",3,1000,20) ("PreyStation",3,2500,37) 

Test case 10:
Products in Supermarket: ("Apple",0,5,200) ("ZZZBOX",3,1000,20) ("XXBOX",3,2000,10) ("PreyStation",3,2500,37) ("YBOX",3,3000,40) 
Update result: true
Products in Supermarket: ("Apple",0,5,200) ("ZZZBOX",3,1000,20) ("PreyStation",3,2500,37) ("YBOX",3,3000,40) ("XXBOX",3,9000,10) 
Products in Supermarket Clone: ("Apple",0,5,200) ("ZZZBOX",3,1000,20) ("XXBOX",3,2000,10) ("PreyStation",3,2500,37) ("YBOX",3,3000,40) 
