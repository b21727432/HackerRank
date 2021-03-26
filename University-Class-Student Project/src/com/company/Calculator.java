package com.company;

public class Calculator implements Grade_Calculate{

    @Override
    public int grade_calculator(int mid1weight, int mid1point, int mid2weight, int mid2point, int finalweight, int finalpoint) {

        int finalresult = (mid1point * mid1weight) + (mid2point * mid2weight) + (finalpoint * finalweight);
        return finalresult;

    }


}
