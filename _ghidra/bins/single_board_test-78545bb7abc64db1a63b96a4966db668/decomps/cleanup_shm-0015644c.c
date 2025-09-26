
void cleanup_shm(void)

{
  shmdt(shm_addr);
  return;
}

