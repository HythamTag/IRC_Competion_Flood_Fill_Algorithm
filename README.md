# IRC_Competition_Flood_Fill_Algorithm

I developed this code to fully control autonomous robot that scan the grid full of nodes ( Robot can move over nodes on scan time only ) automatically then solves it using flood fill algorithm although flood fill algorithm is heavy and use a lot of memory however it was perfect for our usage.

## 1- Grid Matrix after Flood FIll Algorithm.
![33](https://user-images.githubusercontent.com/42402820/103431699-19583980-4bdd-11eb-8f62-d44d7cb514d3.jpg)


## 2- Optimized path according to most forward path.
![33 - Copy](https://user-images.githubusercontent.com/42402820/103431710-56bcc700-4bdd-11eb-8c7a-63cd12e40771.jpg)

## 3- retrieve the points in for of x,y.
![POINTS](https://user-images.githubusercontent.com/42402820/103431916-9a650000-4be0-11eb-913b-48e830427a84.jpg)


## 4- Convert the points into Polarity ( North, South, East, West )
![Polarity](https://user-images.githubusercontent.com/42402820/103431917-9c2ec380-4be0-11eb-883f-080bae718fe3.jpg)

| delta X | delta Y | Polarity |
|:-------:|:-------:|:--------:|
|    0    |    1    |   North  |
|    0    |    -1   |   South  |
|    1    |    0    |   East   |
|    -1   |    0    |   West   |




## 5- Convert Polarity into Direction (Forward, Backward, Left, Right)
![Direction](https://user-images.githubusercontent.com/42402820/103431918-9d5ff080-4be0-11eb-8951-6022f5656255.jpg)


| Polarity 1 	| Polarity 2 	| Direction 	|
|:----------:	|:----------:	|:---------:	|
|    North   	|    North   	|  Forward  	|
|    North   	|    East    	|   Right   	|
|    North   	|    West    	|    Left   	|
|    North   	|    South   	|    Back   	|
|    South   	|    North   	|    Back   	|
|    South   	|    East    	|    Left   	|
|    South   	|    West    	|   Right   	|
|    South   	|    South   	|  Forward  	|
|    East    	|    North   	|    Left   	|
|    East    	|    East    	|  Forward  	|
|    East    	|    West    	|    Back   	|
|    East    	|    South   	|   Right   	|
|    West    	|    North   	|   Right   	|
|    West    	|    East    	|    Back   	|
|    West    	|    West    	|  Forward  	|
|    West    	|    South   	|    Left   	|

At the end you get an array {F,F,F,F,F,F,F,F,R,F,F,F,F,F} that describes how you will move more the start point to end point.


