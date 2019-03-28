PROJECT(yc)

FILE(GLOB yc_SRCS
	    devil.hpp
   	 	devil.cpp
 	   	main.cpp
		Sort.h
		Sort.cpp
		ready.h
		readySort.cpp
		Robot.h
		Robot.cpp	
		class.h
		Info.h
		Info.cpp
		Task.h
		Task.cpp
		Cn.cpp
		Cn.h 
		Cnn.cpp
		Cnn.h
		readyTask.cpp
		readyTask.h 
		#action.h
		action.cpp
		#play.h
		play.cpp
		update.h
		update.cpp	
		graph.h
		graph.cpp
)
SOURCE_GROUP("" FILES ${yc_SRCS})

ADD_EXECUTABLE(yc ${yc_SRCS})

ADD_DEPENDENCIES(yc frame utility)
TARGET_LINK_LIBRARIES(yc frame utility ${Boost_LIBRARIES})
