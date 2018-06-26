/*
 *
 ********************************************************************************************
 * AUTHOR : Akash Kandpal                                                                    *
 * Language: C++14                                                                          *
 * Motto : The master has failed more times than the beginner has even tried.               *                                                                *
 * IDE used: Atom                                                                           *
 * My Domain : http://harrypotter.tech/                                                     *
 ********************************************************************************************
 *
 */
    #include <bits/stdc++.h>

    using namespace std;

    const int inf = 1e9;

    void print1(auto output){
        for(int i = 0; i < output.size(); i++)
{
     cout <<"["<< output[i].first << ", " << output[i].second <<"]";
}
cout<<endl;
    }
        void print2(auto output){
            cout<<"[";
        for(int i = 0; i < output.size(); i++)
{
     cout << output[i];
}
cout<<"]";
cout<<endl;
    }

    int main(int argc, char *argv[]) {
      int T;
      cin >> T;
      while (T--) {
        int n, d;
        cin >> n >> d;
        vector<int> a(n + 1, 0);
        vector<pair<int, int>> st(1, {0, 0});
        int ans = inf;
        for (int i = 1; i <= n; i++) {
          cin >> a[i];
          a[i] += a[i - 1];
          auto it = lower_bound(st.begin(), st.end(), pair<int, int>{a[i] - d, inf});
        //   cout <<(it-st.begin()) ;
        //   cout<<"values===>"<<st[(it-st.begin())].first << " "<< st[(it-st.begin())].second<<"<==values ";
          if (it != st.begin()) {
            --it;
            // cout<<"nhi hai ";
            ans = min(ans, i - it->second);
            // cout<<"i "<<i<<" "<<it->second<<"second";
            // cout<<"ans"<<ans<<"ans";
          }
          while (!st.empty() && st.back().first >= a[i]) {
            //   cout<<" first"<<st.back().first<<" "<<a[i]<<"a[i]"<<" "<<i<<" i";
              st.pop_back();
          }
        //   print1(st);
          st.push_back({a[i], i});
        //   print1(st);
        }
        cout << (ans == inf ? -1 : ans) << endl;
      }
      return 0;
    }
