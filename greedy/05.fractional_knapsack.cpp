class Solution
{
    public:
    class Product{
        public:
        int value;
        int weight;
        double profit;
    };
    static bool cmp(Product a,Product b){
        return a.profit>b.profit;
    }
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        vector<Product> bag(n);
        for(int i=0;i<n;i++){
            bag[i]={arr[i].value,arr[i].weight,static_cast<double>(arr[i].value)/arr[i].weight};
        }
        sort(bag.begin(),bag.end(),cmp);
        int weight=0;
        int count=0;
        double value=0.0;
        while(count<n && (weight+bag[count].weight)<W  ){
            weight+=bag[count].weight;
            value+=(double)bag[count].value;
            count++;
        }
        double rem=0;
        if(count<n){
            rem=(W-weight)*bag[count].profit;
        }
        return value+rem;
    }
        
};