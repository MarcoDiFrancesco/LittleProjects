package com.marcodifrancesco;

import java.io.Serializable;
import java.util.Calendar;

/**
 *
 * @author marco
 */
public class Counter implements Serializable {
    int count = 0;
    Calendar timeStamp;
    
    public void increase() {
        count++;
        timeStamp = Calendar.getInstance();
    }
    
    @Override
    public String toString() {
        StringBuffer s = null;
        if(count == 0) {
            s = new StringBuffer("<p>No hits yet</p>");
        } else {
            s = new StringBuffer("<p>");
            s.append("Hits: ");
            s.append(count);
        }
        return s.toString();
    }
}
