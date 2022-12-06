1. open file
2. read file line
3. if end of line
		\n
		read next line
//
1. open file (main)
2. create buffer from BUFFERSIZE + malloc
3. read() buffer -> buffer is filled. Keep the cursor head at next call
4. strjoin buffer + stash
5. look in stash if \n
	if yes
		print stash
		free buffer
		return (stash)
	if no
		repeat: buffer moves to the next set of BUFFERSIZE
