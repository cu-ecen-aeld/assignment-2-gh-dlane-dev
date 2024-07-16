/*
* @brief - Writer aplication
*/
#include <stddef.h>
#include <syslog.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

#define WRITER_EXPECTED_ARGUMENTS (3)
#define WRITER_ERROR (1)

int main(int argc, char* argv[])
{
  int result = WRITER_ERROR;

  openlog(NULL, 0, LOG_USER);

  if (argc == WRITER_EXPECTED_ARGUMENTS) {

    int fd = open(argv[1], O_WRONLY | O_TRUNC | O_CREAT, S_IRWXU | S_IRWXG | S_IROTH); 


    if (fd >= 0) {
      size_t write_size = strlen(argv[2]);
      ssize_t written_size = write(fd, argv[2], write_size);

      if (written_size == write_size) {
        syslog(LOG_DEBUG, "Writing %s to %s", argv[2], argv[1]);
        result = 0;
      } else {
        syslog(LOG_ERR, "Failed to write expected length %ld, wrote %ld, errno %d", write_size, written_size, errno);
      }

      close(fd);
    } else {
      syslog(LOG_ERR, "Failed to open %s, errno %d", argv[1], errno); 
    }

  } else {
    syslog(LOG_ERR, "Incorrect number of parameters supplied");
  }


  closelog();

  return result;
}
