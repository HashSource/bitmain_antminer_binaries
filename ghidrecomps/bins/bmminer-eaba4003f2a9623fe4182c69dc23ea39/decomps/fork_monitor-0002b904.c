
/* WARNING: Unknown calling convention */

void fork_monitor(void)

{
  int iVar1;
  __sighandler_t p_Var2;
  __sighandler_t p_Var3;
  int pfd [2];
  sighandler_t sr1;
  sighandler_t sr0;
  int r;
  
  iVar1 = pipe(pfd);
  if (iVar1 < 0) {
    perror("pipe - failed to create pipe for --monitor");
                    /* WARNING: Subroutine does not return */
    exit(1);
  }
  fflush(stderr);
  iVar1 = dup2(pfd[1],2);
  if (iVar1 < 0) {
    perror("dup2 - failed to alias stderr to write end of pipe for --monitor");
                    /* WARNING: Subroutine does not return */
    exit(1);
  }
  iVar1 = close(pfd[1]);
  if (iVar1 < 0) {
    perror("close - failed to close write end of pipe for --monitor");
                    /* WARNING: Subroutine does not return */
    exit(1);
  }
  p_Var2 = signal(0xd,(__sighandler_t)0x1);
  p_Var3 = signal(0xd,(__sighandler_t)0x1);
  if ((p_Var2 == (__sighandler_t)0xffffffff) || (p_Var3 == (__sighandler_t)0xffffffff)) {
    perror("signal - failed to edit signal mask for --monitor");
                    /* WARNING: Subroutine does not return */
    exit(1);
  }
  forkpid = fork();
  if (forkpid < 0) {
    perror("fork - failed to fork child process for --monitor");
                    /* WARNING: Subroutine does not return */
    exit(1);
  }
  if (forkpid != 0) {
    iVar1 = close(pfd[0]);
    if (iVar1 < 0) {
      perror("close - failed to close read end of pipe for --monitor");
                    /* WARNING: Subroutine does not return */
      exit(1);
    }
    return;
  }
  iVar1 = dup2(pfd[0],0);
  if (iVar1 < 0) {
    perror("dup2 - in child, failed to alias read end of pipe to stdin for --monitor");
                    /* WARNING: Subroutine does not return */
    exit(1);
  }
  close(pfd[0]);
  if (iVar1 < 0) {
    perror("close - in child, failed to close read end of  pipe for --monitor");
                    /* WARNING: Subroutine does not return */
    exit(1);
  }
  execl("/bin/bash","/bin/bash",&DAT_00074c10,opt_stderr_cmd,0);
  perror("execl - in child failed to exec user specified command for --monitor");
                    /* WARNING: Subroutine does not return */
  exit(1);
}

