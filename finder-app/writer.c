/*
 * writer.c
 *
 * Usage:
 *   ./writer <writefile> <writestr>
 
 * Author: Sujitpatel2739
 */

#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>
#include <errno.h>
#include <string.h>

int main(int argc, char *argv[])
{
    FILE *fp;

    /* Initialize syslog */
    openlog("writer", LOG_PID, LOG_USER);

    /* Check number of arguments */
    if (argc != 3)
    {
        syslog(LOG_ERR, "Invalid number of arguments");
        fprintf(stderr, "Error: Two arguments required.\n");
        closelog();
        return EXIT_FAILURE;
    }

    const char *writefile = argv[1];
    const char *writestr = argv[2];

    /* Log debug message */
    syslog(LOG_DEBUG, "Writing %s to %s", writestr, writefile);

    /* Open file for writing (create or overwrite) */
    fp = fopen(writefile, "w");
    if (fp == NULL)
    {
        syslog(LOG_ERR, "Failed to open file %s: %s",
               writefile, strerror(errno));
        closelog();
        return EXIT_FAILURE;
    }

    /* Write string to file */
    if (fprintf(fp, "%s", writestr) < 0)
    {
        syslog(LOG_ERR, "Failed to write to file %s: %s",
               writefile, strerror(errno));
        fclose(fp);
        closelog();
        return EXIT_FAILURE;
    }

    /* Close file */
    if (fclose(fp) != 0)
    {
        syslog(LOG_ERR, "Failed to close file %s: %s",
               writefile, strerror(errno));
        closelog();
        return EXIT_FAILURE;
    }

    closelog();
    return EXIT_SUCCESS;
}
