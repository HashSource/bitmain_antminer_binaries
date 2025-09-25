
void engine_list_cleanup(void)

{
  if (engine_list_head != (ENGINE *)0x0) {
    do {
      ENGINE_remove(engine_list_head);
    } while (engine_list_head != (ENGINE *)0x0);
  }
  return;
}

