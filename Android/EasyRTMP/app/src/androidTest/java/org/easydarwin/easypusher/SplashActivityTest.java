package org.easydarwin.easypusher;


import android.support.test.espresso.ViewInteraction;
import android.support.test.rule.ActivityTestRule;
import android.support.test.runner.AndroidJUnit4;
import android.test.suitebuilder.annotation.LargeTest;

import org.junit.Rule;
import org.junit.Test;
import org.junit.runner.RunWith;

import static android.support.test.espresso.Espresso.onView;
import static android.support.test.espresso.Espresso.pressBack;
import static android.support.test.espresso.action.ViewActions.click;
import static android.support.test.espresso.action.ViewActions.scrollTo;
import static android.support.test.espresso.matcher.ViewMatchers.isDisplayed;
import static android.support.test.espresso.matcher.ViewMatchers.withId;
import static android.support.test.espresso.matcher.ViewMatchers.withParent;
import static android.support.test.espresso.matcher.ViewMatchers.withText;
import static org.hamcrest.Matchers.allOf;

@LargeTest
@RunWith(AndroidJUnit4.class)
public class SplashActivityTest {

    @Rule
    public ActivityTestRule<SplashActivity> mActivityTestRule = new ActivityTestRule<>(SplashActivity.class);

    @Test
    public void splashActivityTest() {
        // Added a sleep statement to match the app's execution delay.
        // The recommended way to handle such scenarios is to use Espresso idling resources:
        // https://google.github.io/android-testing-support-library/docs/espresso/idling-resource/index.html


        ViewInteraction appCompatButton = onView(
                allOf(withId(R.id.btn_switch), withText("推送"), isDisplayed()));
        appCompatButton.perform(click());

        ViewInteraction appCompatButton2 = onView(
                allOf(withId(R.id.btn_setting), withText("设置"), isDisplayed()));
        appCompatButton2.perform(click());

        pressBack();

        ViewInteraction appCompatCheckBox = onView(
                allOf(withId(R.id.only_push_audio), withText("仅推送音频")));
        appCompatCheckBox.perform(scrollTo(), click());

        ViewInteraction appCompatButton3 = onView(
                allOf(withId(R.id.btn_save), withText("保存")));
        appCompatButton3.perform(scrollTo(), click());

        ViewInteraction appCompatButton4 = onView(
                allOf(withId(R.id.btn_setting), withText("设置"), isDisplayed()));
        appCompatButton4.perform(click());

        pressBack();

        ViewInteraction appCompatCheckBox2 = onView(
                allOf(withId(R.id.only_push_audio), withText("仅推送音频")));
        appCompatCheckBox2.perform(scrollTo(), click());

        ViewInteraction appCompatButton5 = onView(
                allOf(withId(R.id.btn_save), withText("保存")));
        appCompatButton5.perform(scrollTo(), click());

        pressBack();

        ViewInteraction appCompatButton6 = onView(
                allOf(withId(android.R.id.button2), withText("取消"),
                        withParent(allOf(withId(R.id.buttonPanel),
                                withParent(withId(R.id.parentPanel)))),
                        isDisplayed()));
        appCompatButton6.perform(click());

    }

}
