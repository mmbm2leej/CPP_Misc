Spacebus3000 : It痴 the year 3000 and there痴 a company called Spacebus that offers rides between certain spaceports. Imagine that you are given a file listing the routes that Spacebus offers. Here痴 an example of what the file could look like・

Infrared Spacehub, Grand Nebula Spaceport
Blue Nova Space Market, Heavy Element Spacemine
Asteroid Research Institute, Oort Cloud Observation Facility
Infrared Spacehub, Oort Cloud Observation Facility
Oort Cloud Observation Facility, Double Ring Space Habitat

Each line means there痴 a Spacebus route going back and forth between the two spaceports. In the example above, one can take a Spacebus from Asteroid Research Institute to Oort Cloud Observation Facility, and also from Oort Cloud Observation Facility to Infrared Spacehub, and also from Infrared Spacehub to Grand Nebula Spaceport. So it follows that one could travel all the way from Asteroid Research Institute to Grand Nebula Spaceport just using Spacebus. On the other hand, there is no way to get from Asteroid Research Institute to Heavy Element Spacemine using Spacebus.

Write a Java (or C++) program called 鉄pacebus3000・that takes three arguments - the name of a file listing Spacebus痴 routes and the names of two spaceports ・and outputs 土es・or 渡o・depending on whether one could travel from one of the spaceports to the other of the spaceports just using Spacebus. If either of the spaceport arguments isn't in the file, then the program should output "no".

Here are some sample Java interactions, assuming the example file above is named spacebusroutes.txt・

java Spacebus3000 spacebusroutes.txt 徹ort Cloud Observation Facility・鄭steroid Research Institute・
> yes

java Spacebus3000 spacebusroutes.txt 鄭steroid Research Institute・敵rand Nebula Spaceport・
> yes

java Spacebus3000 spacebusroutes.txt 鄭steroid Research Institute・滴eavy Element Spacemine・
> no

java Spacebus3000 spacebusroutes.txt 鄭steroid Research Institute・Pluto
> no

You can assume that none of the names of the spaceports will contain commas. That is, in the file, there will only be one comma on each line, separating the names of the two spaceports.

You won't need to write any code to handle the quotes that appear around the spaceport names in the example command-line interactions. The command-line environment will naturally take care of that. In the last example command-line interaction, as far as the Java method Spacebus3000.main() is concerned, args[1] is Asteroid Research Institute, and args[2] is Pluto.

