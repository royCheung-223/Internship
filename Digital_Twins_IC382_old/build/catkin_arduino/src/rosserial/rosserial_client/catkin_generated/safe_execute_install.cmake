execute_process(COMMAND "/home/iastaff/Internship/Digital_Twins_IC382_old/build/catkin_arduino/src/rosserial/rosserial_client/catkin_generated/python_distutils_install.sh" RESULT_VARIABLE res)

if(NOT res EQUAL 0)
  message(FATAL_ERROR "execute_process(/home/iastaff/Internship/Digital_Twins_IC382_old/build/catkin_arduino/src/rosserial/rosserial_client/catkin_generated/python_distutils_install.sh) returned error code ")
endif()
