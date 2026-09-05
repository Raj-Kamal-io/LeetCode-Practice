class Solution { 
    public int minFlips(int a, int b, int c) { 
        int count = 0; 
         
        for(int i = 0; i < 32; i++){ 
            if(((c>>i)&1) == 1){ 
                if(((a>>i)&1) == 0  &&((b>>i)&1) == 0){ 
                    count++; 
                } 
            } else { 
                if(((a>>i)&1) == 1) count++; 
                if(((b>>i)&1) == 1) count++; 
            } 
        } 
        return count; 
    } 
}