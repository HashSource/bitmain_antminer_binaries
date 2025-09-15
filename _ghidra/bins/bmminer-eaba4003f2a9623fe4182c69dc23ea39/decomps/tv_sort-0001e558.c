
int tv_sort(work *worka,work *workb)

{
  work *workb_local;
  work *worka_local;
  
  return (worka->tv_staged).tv_sec - (workb->tv_staged).tv_sec;
}

