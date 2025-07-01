// *
// * hpdev
// * когда уматывают в сани, то все нормально
// *

package com.metasamp.gtasa;

import android.os.Bundle;

import com.wardrumstudios.utils.WarMedia;
import java.io.File;

public class GTASA extends WarMedia {
    public static GTASA gtasaSelf;
    static String vmVersion;
    boolean UseExpansionPack = false;

    static {
        System.out.println("**** Loading SO's");
        try {
            vmVersion = System.getProperty("java.vm.version");
            System.out.println("vmVersion " + vmVersion);
            System.loadLibrary("SCAnd");
            System.loadLibrary("GTASA");
            System.loadLibrary("ImmEmulatorJ");
            System.loadLibrary("libSAMP");
        } catch (ExceptionInInitializerError | UnsatisfiedLinkError e) {
            System.out.println(e.getMessage());
        }
    }
    @Override
    public void onCreate(Bundle bundle) {
        System.out.println("**** onCreate");
        gtasaSelf = this;
        expansionFileName = "main.8." + getPackageName() + ".obb";
        patchFileName = "patch.8." + getPackageName() + ".obb";
        apkFileName = GetPackageName(getPackageName());
        baseDirectory = GetGameBaseDirectory();
        AllowLongPressForExit = true;
        String[] strArr = {"anim", "audio", "data", "models", "texdb"};
        for (int i = 0; i < 5; i++) {
            String str = strArr[i];
            File file = new File(baseDirectory + str);
            UseExpansionPack = !file.exists() || !file.isDirectory();
        }
        if (UseExpansionPack) {
            xAPKS = new WarMedia.XAPKFile[2];
            xAPKS[0] = new WarMedia.XAPKFile(true, 8, 1967561852L);
            xAPKS[1] = new WarMedia.XAPKFile(false, 8, 625313014L);
        }
        wantsMultitouch = true;
        wantsAccelerometer = true;
        RestoreCurrentLanguage();
        super.onCreate(bundle);
        SetReportPS3As360(false);
    }

    @Override
    public boolean ServiceAppCommand(String str, String str2) {
        if (str.equalsIgnoreCase("SetLocale")) {
            SetLocale(str2);
        }
        return false;
    }

    @Override
    public int ServiceAppCommandValue(String str, String str2) {
        if (str.equalsIgnoreCase("GetDownloadBytes")) {
            return 0;
        }
        if (str.equalsIgnoreCase("GetDownloadState")) {
            return 4;
        }
        return (str.equalsIgnoreCase("GetNetworkState") && isNetworkAvailable()) ? 1 : 0;
    }

    @Override
    public void onStart() {
        System.out.println("**** onStart");
        super.onStart();
    }

    @Override
    public void onRestart() {
        System.out.println("**** onRestart");
        super.onRestart();
    }

    @Override
    public void onResume() {
        System.out.println("**** onResume");
        super.onResume();
    }

    @Override
    public void onPause() {
        System.out.println("**** onPause");
        super.onPause();
    }

    @Override
    public void onStop() {
        System.out.println("**** onStop");
        super.onStop();
    }

    @Override
    public void onDestroy() {
        System.out.println("**** onDestroy");
        super.onDestroy();
    }

    @Override
    public boolean CustomLoadFunction() {
        return CheckIfNeedsReadPermission(gtasaSelf);
    }

    public static void staticEnterSocialClub() {
        gtasaSelf.EnterSocialClub();
    }

    public static void staticExitSocialClub() {
        gtasaSelf.ExitSocialClub();
    }

    public void EnterSocialClub() {
        System.out.println("**** EnterSocialClub");
    }

    public void ExitSocialClub() {
        System.out.println("**** ExitSocialClub");
    }
}