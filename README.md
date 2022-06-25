# Final-Practical-Work-Universidad-Favaloro-LP1-spanish-work-
By Adriel Levy, Bautista Farfaglia and Juan Manuel González Kapnik.

Final note: 08/10.

## Table of contents
1. [Project Description](#description)
2. [How to Install and Run the Project](#howto)
3. [Considerations](#considerations)
4. [License](#license)
5. [References](#references)

## Project Description <a name="description"></a>

The objective of this practical work is to simulate an AeroClub by means of a Watch Tower. In this way, it seeks to regulate the airplanes that try to take off, land and park.

It was programmed in C++ language, using inheritance, polymorphism, dynamic_cast, overloading, exception control, attributes and methods (both const and static), dynamic memory, function and friend class, random algorithm and time.h functions.

The most important challenge we had to face was the high amount of overloads requested, and how these could fit in the practical work. On the other hand, the use of MRUV to simulate the time/distance relationship of airplanes was a great achievement in physics application.

## How to Install and Run the Project <a name="howto"></a>

To use the project, we debug it using Visual Studio 2022 Community. We understand that depending on the version of the IDE there may be conflicts. 

## Considerations <a name="considerations"></a>
* The take-off speed of the aircraft is in the Practical Work's instruction, but the landing speed is not. Based on the fact that the aircraft landing speed is lower than the take-off speed, we conclude:

  Since CESSNA aircraft have 200km/h speed for takeoff, they will have 180km/h for landing, while Biplanes have 240 km/h takeoff, they will have 220km/h landing. 

* The aircraft conditions are proposed for take-off, but not for landing. For the CESSNA it is proposed to raise the ailerons and turn off the automatic flight stabilization control at the end of parking. For biplanes your pitch angle returns to 0 before parking (on landing itself).

* Comments of any get/set, and some polymorphic methods (in derived classes) were avoided.

* To avoid confusion between relationships, the use of friend class is not shown in the UML.

## License <a name="license"></a>
This Practical Work is subject to GPL-3.0 license, more information in the LICENSE.md file.

---

#### References <a name="references"></a>
[std::exception](https://en.cppreference.com/w/cpp/error/exception)

[const_cast conversion](https://en.cppreference.com/w/cpp/language/const_cast)

