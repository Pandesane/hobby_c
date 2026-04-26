
#include "./file_stream_types.h"
#include "./dynamic_array.h"

#ifndef FILESTREAM_H
#define FILESTREAM_H
#define MAX_BUFFER_SIZE 300
typedef int Boolean;

// File stream
/*
openFIle
getNextLine
previousLine
nextLine
parseLines
hasNextLine
setFileBufferSize
getNumberOfLine
releaseStream

*/
void file_stream_printer(void *data);
FILESTREAM *open_file(char *fileName);
LINE get_current_line(FILESTREAM *fileStream);
LINE get_next_line(FILESTREAM *fileStream);
LINE get_previous_line(FILESTREAM *fileStream);
Boolean has_next_line(FILESTREAM *fileStream);
void load_file_contents(FILESTREAM *file_stream);
void print_file_contents(FILESTREAM *file_stream);
void set_file_buffer_size(FILESTREAM *fileStream);


#endif