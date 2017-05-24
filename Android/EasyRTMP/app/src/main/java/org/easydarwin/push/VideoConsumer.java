package org.easydarwin.push;

import java.io.IOException;

/**
 * Created by apple on 2017/5/13.
 */

public interface VideoConsumer {
    public void onVideoStart(int width, int height) throws IOException;

    public int onVideo(byte []data, int format);

    public void onVideoStop();
}
