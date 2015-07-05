#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <dlfcn.h>
#include <notify.h>
#include <spawn.h>
#include <signal.h>
#include <CoreFoundation/CoreFoundation.h>

int main(int argc, char **argv) {
	if (argc > 1) {
		return 0;
	}
	pid_t pid;
	int status;
	const char *argg[] = {"sysctl", "-w", "net.inet.icmp.drop_redirect=1", NULL};
	posix_spawn(&pid, "/usr/sbin/sysctl", NULL, NULL, (char* const*)argg, NULL);
	waitpid(pid, &status, WEXITED);
	return 0;
}