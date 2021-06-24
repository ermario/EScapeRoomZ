# EScapeRoomZ

This is a text-game based created from a Zork clone

The objective of the game is to find out what is going on in your house
Explore, take items, survive and exit your house. 

GitHub: https://github.com/ermario/EScapeRoomZ

#HELPFUL COMMANDS

	- Look | l
	- Look (entity)| l (entity)
	- Inventory | i
	- Go (direction) | Move (direction) | mv (direction)
	directions: (straight/right/left/behind)
	- Take (item) | Pick (item)
	- Take (item) from (entity)| Pick (item) from (entity)
	- Drop (item) | Put (item)
	- Equip (item) | eq (item) | Use (item)
	- Unequip (item) | uneq (item)
	- Read (note)
	- Unlock (direction) with (key)
	
#TIPS

	 - Entities may contain items inside
	 - Use the flashlight to see in the dark
	 - Use a key to unlock a door
	 - Read a note to get more information or hints

# PERSONAL NOTES

This was an exercise as an access test for a master’s degree in videogame development form UPC school in Barcelona.
The exercise was meant to prove your knowledge and skills in c++ programming. To test our knowledge on C/C++ we will code a simple text mode conversational game. We should be
aiming for a well-organized code (efficiency is not important right now) where we explore C++ capabilities
like polymorphism.

I will describe my personal experience for this task.

I haven't code in c++ for 5 years, so I really struggled adapting for the language at the beginning.
First, I saw some examples on the internet and tried to understand everything, that took most of the time.
I had to recap many concepts, pointers, polymorphism, classes, etc. For the las 3 years I've been coding python microservices, so all of that was missing.
I define myself adaptive in this kind of situations so after some researching and recapping, I started to code the solution.
Based on the example given and the structure required I managed to do a little scape room.

The main features are:
	- Moving through rooms
	- Exits closed / locked
	- Minigame in which you can die if you enter the wrong room
	- Dark room (can't see anything) you must use flashlight
	- Unlock exit for finishing the game.
	
It was really frustrating at the beginning because I forgot a lot from c++, but at the end I really enjoyed making the game and even if I'm not accepted on the course, I will keep doing some personal projects and learning more because game development is something I really want to do.

#SOMETHING TO KNOW ABOUT THE CODE:

I've used Visual Studio 2019 Community edition and the code has 0 errors and 0 warnings.
	 
# LICENSE

MIT License

Copyright (c) 2021 ermario

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
