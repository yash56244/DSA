long long  multiplyTwoLists (Node* l1, Node* l2)
{
  long long n1 = 0, n2 = 0;
  const int mod = 1e9 + 7;
  while(l1 || l2){
      if(l1){
        n1 = (n1*10)%mod + l1->data;
        l1 = l1->next;
      }
      if(l2){
          n2 = (n2*10)%mod + l2->data;
          l2 = l2->next;
      }
  }
  long long ans = ((n1%mod)*(n2%mod))%mod;
  if(ans < 0)
    ans+=mod;
  return ans;
}
