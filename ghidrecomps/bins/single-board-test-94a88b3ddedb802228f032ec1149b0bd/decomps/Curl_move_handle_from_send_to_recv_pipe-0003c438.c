
void Curl_move_handle_from_send_to_recv_pipe(int param_1,int param_2)

{
  undefined4 uVar1;
  int *piVar2;
  
  piVar2 = **(int ***)(param_2 + 600);
  while( true ) {
    if (piVar2 == (int *)0x0) {
      return;
    }
    if (*piVar2 == param_1) break;
    piVar2 = (int *)piVar2[2];
  }
  Curl_llist_move(*(int ***)(param_2 + 600),piVar2,*(int *)(param_2 + 0x25c),
                  *(undefined4 *)(*(int *)(param_2 + 0x25c) + 4));
  if ((undefined4 *)**(undefined4 **)(param_2 + 600) == (undefined4 *)0x0) {
    return;
  }
  uVar1 = *(undefined4 *)**(undefined4 **)(param_2 + 600);
  *(undefined *)(param_2 + 0x255) = 0;
  Curl_expire(uVar1,1);
  return;
}

