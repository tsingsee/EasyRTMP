package org.easydarwin.push;

import org.easydarwin.audio.AudioStream;

import dagger.Component;

/**
 * Created by apple on 2017/5/13.
 */
@Component(modules = MediaStream.class)
public interface MuxerModule {
    void inject(HWConsumer consumer);
    void inject(AudioStream MedisStream);
}

