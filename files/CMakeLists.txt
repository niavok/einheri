
INSTALL(DIRECTORY "etc/"
        DESTINATION "etc/einheri"
			  COMPONENT etc
				FILES_MATCHING PATTERN ".svn" EXCLUDE)

INSTALL(DIRECTORY "share/"
        DESTINATION "share/einheri"
			  COMPONENT share 
				FILES_MATCHING PATTERN ".svn" EXCLUDE)

