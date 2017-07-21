package org.easydarwin.easypusher;

import android.content.ActivityNotFoundException;
import android.content.Intent;
import android.databinding.DataBindingUtil;
import android.net.Uri;
import android.os.Bundle;
import android.os.Environment;
import android.support.annotation.Nullable;
import android.support.v4.app.Fragment;
import android.support.v4.app.FragmentPagerAdapter;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.view.ActionMode;
import android.support.v7.widget.GridLayoutManager;
import android.support.v7.widget.LinearLayoutManager;
import android.support.v7.widget.RecyclerView;
import android.support.v7.widget.Toolbar;
import android.text.TextUtils;
import android.util.SparseArray;
import android.view.LayoutInflater;
import android.view.MenuItem;
import android.view.View;
import android.view.ViewGroup;
import android.widget.CheckBox;
import android.widget.CompoundButton;
import android.widget.ImageView;
import android.widget.Toast;

import com.bumptech.glide.Glide;


import org.easydarwin.easypusher.databinding.ActivityMediaFilesBinding;
import org.easydarwin.easypusher.databinding.FragmentMediaFileBinding;
import org.easydarwin.easypusher.databinding.ImagePickerItemBinding;

import java.io.File;
import java.io.FilenameFilter;

public class MediaFilesActivity extends AppCompatActivity {

    private ActivityMediaFilesBinding mDataBinding;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        mDataBinding = DataBindingUtil.setContentView(this, R.layout.activity_media_files);
        Toolbar toolbar = (Toolbar) findViewById(R.id.toolbar);
        setSupportActionBar(toolbar);
        getSupportActionBar().setDisplayHomeAsUpEnabled(true);
        mDataBinding.viewPager.setAdapter(new FragmentPagerAdapter(getSupportFragmentManager()) {
            @Override
            public int getCount() {
                return 2;
            }


            public Fragment getItem(int position) {
                Bundle args = new Bundle();
                args.putBoolean(LocalFileFragment.KEY_IS_RECORD, position == 0);
                return Fragment.instantiate(MediaFilesActivity.this, LocalFileFragment.class.getName(), args);
            }

            @Override
            public CharSequence getPageTitle(int position) {
                return position == 0 ? "录像":"抓拍";
            }
        });
    }


    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        if (item.getItemId() == android.R.id.home) {
            finish();
            return true;
        }
        return super.onOptionsItemSelected(item);
    }

    public static class LocalFileFragment extends Fragment implements CompoundButton.OnCheckedChangeListener, View.OnClickListener {

        public static final String KEY_IS_RECORD = "key_last_selection";
        private boolean mShowMp4File;
        private ActionMode mActionMode;
        private FragmentMediaFileBinding mBinding;

        SparseArray<Boolean> mImageChecked;

        private String mSuffix;
        File mRoot = null;
        File[] mSubFiles;
        int mImgHeight;


//
//        public class MyFileAdapter extends BaseAdapter {
//
//
//            @Override
//            public int getCount() {
//                if (mSubFiles == null) return 0;
//                return mSubFiles.length;
//            }
//
//            @Override
//            public Object getItem(int position) {
//                return mSubFiles[position];
//            }
//
//            @Override
//            public long getItemId(int position) {
//                return position;
//            }
//
//            @Override
//            public View getView(int position, View convertView, ViewGroup parent) {
//                boolean newCreated = false;
//                if (convertView == null) {
//                    newCreated = true;
//                    convertView = LayoutInflater.from(getActivity()).inflate(
//                            R.layout.local_file_item, parent, false);
//                }
//                File fc = (File) getItem(position);
//                initViewByFile(fc, convertView, newCreated);
//                View divider = convertView.findViewById(R.id.item_divider);
//                if (getListView().isItemChecked(position)) {
//                    divider.setBackgroundResource(R.drawable.file_list_item_divider_bg_checked);
//                } else {
//                    divider.setBackgroundResource(R.drawable.file_list_item_divider_bg);
//                }
//                return convertView;
//            }
//
//            private void initViewByFile(File fc, View convertView, boolean newCreated) {
//                // 读取文件
//                if (!newCreated) {
//                    AsyncTask t = (AsyncTask) convertView.getTag();
//                    if (t != null) t.cancel(true);
//                }
//                ImageView imageView = (ImageView) convertView.findViewById(R.id.item_thumb);
//
//                if (".jpg".equals(mSuffix)) {
//                    Glide.with(convertView.getContext()).load(fc).crossFade().into(imageView);
//                } else {
//                    convertView.setTag(TheApp.showThumbnail(imageView, fc.getPath(), mImgHeight));
//                }
//                TextView name = (TextView) convertView.findViewById(R.id.item_name);
//                String fileName = fc.getPath();
//                int index = fileName.lastIndexOf('/');
//                fileName = fileName.substring(index + 1, fileName.length() - 4);
//                name.setText(fileName);
//            }
//
//            public void removeAt(int i) {
//                List<File> files = new ArrayList<File>();
//                for (File f : mSubFiles) {
//                    files.add(f);
//                }
//                files.remove(i);
//                mSubFiles = new File[files.size()];
//                files.toArray(mSubFiles);
//            }
//        }

        @Override
        public void onCreate(Bundle savedInstanceState) {
            super.onCreate(savedInstanceState);
            setHasOptionsMenu(false);

            mImageChecked = new SparseArray<>();

            mShowMp4File = getArguments().getBoolean(KEY_IS_RECORD);
            mSuffix = mShowMp4File ? ".mp4" : ".jpg";
            File easyPusher = new File(Environment.getExternalStorageDirectory() + (EasyApplication.isRTMP()?"/EasyRTMP":"/EasyPusher"));
            easyPusher.mkdir();
            mRoot = easyPusher;
            File[] subFiles = mRoot.listFiles(new FilenameFilter() {

                @Override
                public boolean accept(File dir, String filename) {
                    return filename.endsWith(mSuffix);
                }
            });
            if (subFiles == null) subFiles = new File[0];
            mSubFiles = subFiles;
            mImgHeight = (int) (getResources().getDisplayMetrics().density * 100 + 0.5f);
        }

        @Override
        public View onCreateView(LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState) {
            // TODO Auto-generated method stub
            // return super.onCreateView(inflater, container, savedInstanceState);
//            DataBindingUtil.inflate(inflater, container, false);
            mBinding = DataBindingUtil.inflate(inflater, R.layout.fragment_media_file, container, false);
            return mBinding.getRoot();
        }

        @Override
        public void onActivityCreated(@Nullable Bundle savedInstanceState) {
            // TODO Auto-generated method stub
            super.onActivityCreated(savedInstanceState);
            GridLayoutManager layoutManager = new GridLayoutManager(getContext(), 3);
            layoutManager.setOrientation(LinearLayoutManager.VERTICAL);

            mBinding.recycler.setLayoutManager(layoutManager);

            mBinding.recycler.setAdapter(new RecyclerView.Adapter() {
                @Override
                public RecyclerView.ViewHolder onCreateViewHolder(ViewGroup parent, int viewType) {
                    ImagePickerItemBinding binding = DataBindingUtil.inflate(getLayoutInflater(null), R.layout.image_picker_item, parent, false);
                    return new ImageItemHolder(binding);
                }

                @Override
                public void onBindViewHolder(RecyclerView.ViewHolder viewHolder, int position) {
                    ImageItemHolder holder = (ImageItemHolder) viewHolder;
                    holder.mCheckBox.setOnCheckedChangeListener(null);
                    holder.mCheckBox.setChecked(mImageChecked.get(position, false));
                    holder.mCheckBox.setOnCheckedChangeListener(LocalFileFragment.this);
                    holder.mCheckBox.setTag(R.id.click_tag, holder);
                    holder.mImage.setTag(R.id.click_tag, holder);

                    Glide.with(getContext()).load(mSubFiles[position]).into(holder.mImage);

                }

                @Override
                public int getItemCount() {
                    return mSubFiles.length;
                }
            });

//            getListView().setOnItemLongClickListener(new AdapterView.OnItemLongClickListener() {
//                @Override
//                public boolean onItemLongClick(AdapterView<?> parent, View view, int position, long id) {
//                    if (mActionMode != null) {
//                        return true;
//                    }
//                    getListView().setChoiceMode(ListView.CHOICE_MODE_MULTIPLE);
//                    getListView().setItemChecked(position, true);
//                    View divider = view.findViewById(R.id.item_divider);
//                    if (getListView().isItemChecked(position)) {
//                        divider.setBackgroundResource(R.drawable.file_list_item_divider_bg_checked);
//                    } else {
//                        divider.setBackgroundResource(R.drawable.file_list_item_divider_bg);
//                    }
//                    AppCompatActivity activity = (AppCompatActivity) getActivity();
//                    mActionMode = activity.startSupportActionMode(new ActionMode.Callback() {
//                        @Override
//                        public boolean onCreateActionMode(ActionMode mode, Menu menu) {
//                            MenuInflater inflater = mode.getMenuInflater();
//                            inflater.inflate(R.menu.local_files_fragment_item_cab, menu);
//                            MenuItem item = menu.findItem(R.id.menu_item_share);
//                            ShareActionProvider shareProvider = (ShareActionProvider) MenuItemCompat.getActionProvider(item);
//                            mProvider = shareProvider;
//
//                            Intent share = new Intent(Intent.ACTION_SEND_MULTIPLE);
//                            share.setType(MimeTypeMap.getSingleton().getMimeTypeFromExtension(mShowMp4File ? "mp4" : "jpg"));
//                            SparseBooleanArray array = getListView().getCheckedItemPositions();
//                            ArrayList<Uri> uris = new ArrayList<Uri>();
//                            for (int i = array.size() - 1; i > -1; i--) {
//                                if (array.valueAt(i)) {
//                                    int pos = array.keyAt(i);
//                                    File fc = (File) getListView().getItemAtPosition(pos);
//                                    uris.add(Uri.fromFile(fc));
//                                }
//                            }
//                            share.putParcelableArrayListExtra(Intent.EXTRA_STREAM, uris);
//                            mProvider.setShareIntent(share);
//                            return true;
//                        }
//
//                        @Override
//                        public boolean onPrepareActionMode(ActionMode actionMode, Menu menu) {
//                            return false;
//                        }
//
//                        @Override
//                        public boolean onActionItemClicked(ActionMode mode, MenuItem item) {
//                            switch (item.getItemId()) {
//                                case R.id.action_delete_items:
//                                    deleteSelectedItems();
//                                    mode.finish(); // Action picked, so close the CAB
//                                    return true;
//                                default:
//                                    return false;
//                            }
//                        }
//
//                        @Override
//                        public void onDestroyActionMode(ActionMode actionMode) {
//                            getListView().setChoiceMode(ListView.CHOICE_MODE_NONE);
//                            getListView().clearChoices();
//                            MyFileAdapter adapter = (MyFileAdapter) getListAdapter();
//                            adapter.notifyDataSetChanged();
//                            mActionMode = null;
//                        }
//                    });
//                    mActionMode.setTitle(String.valueOf(1));
//                    return true;
//                }
//            });


//            getListView().setOnItemClickListener(new AdapterView.OnItemClickListener() {
//                @Override
//                public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
//                    if (mActionMode != null) {
//                        View divider = view.findViewById(R.id.item_divider);
//                        if (getListView().isItemChecked(position)) {
//                            divider.setBackgroundResource(R.drawable.file_list_item_divider_bg_checked);
//                        } else {
//                            divider.setBackgroundResource(R.drawable.file_list_item_divider_bg);
//                        }
//                        if (getListView().getCheckedItemCount() == 0) {
//                            mActionMode.finish();
//                            return;
//                        }
//                        mActionMode.setTitle(String.valueOf(getListView().getCheckedItemCount()));
//                        MyFileAdapter adapter = (MyFileAdapter) getListView().getAdapter();
//                        adapter.notifyDataSetChanged();
//                        if (mProvider != null) {
//                            Intent share = new Intent(Intent.ACTION_SEND_MULTIPLE);
//                            share.setType(MimeTypeMap.getSingleton().getMimeTypeFromExtension(mShowMp4File ? "mp4" : "jpg"));
//                            SparseBooleanArray array = getListView().getCheckedItemPositions();
//                            ArrayList<Uri> uris = new ArrayList<Uri>();
//                            for (int i = array.size() - 1; i > -1; i--) {
//                                if (array.valueAt(i)) {
//                                    int pos = array.keyAt(i);
//                                    File fc = (File) getListView().getItemAtPosition(pos);
//                                    uris.add(Uri.fromFile(fc));
//                                }
//                            }
//                            share.putParcelableArrayListExtra(Intent.EXTRA_STREAM, uris);
//                            mProvider.setShareIntent(share);
//                        }
//                    } else {
//
//                    }
//                }
//            });
        }


        @Override
        public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
            ImageItemHolder holder = (ImageItemHolder) buttonView.getTag(R.id.click_tag);
            int position = holder.getAdapterPosition();
            if (mActionMode != null) {
                mActionMode.invalidate();
            }
//            if (isChecked) {
//                if (mImageChecked.size() == mLimit) {
//                    buttonView.setChecked(false);
//                    return;
//                }
//                mImageChecked.put(position, true);
//                if (mActionMode != null) {
//                    mActionMode.setTitle(String.format("%d/%d", mImageChecked.size(), mLimit));
//                    return;
//                }
//                mActionMode = mToolbar.startActionMode(mCallback);
//            } else {
//                mImageChecked.remove(position);
//                if (mActionMode != null) {
//                    if (mImageChecked.size() == 0) {
//                        mActionMode.finish();
//                        mActionMode = null;
//                        return;
//                    }
//                    mActionMode.setTitle(String.format("%d/%d", mImageChecked.size(), mLimit));
//                    return;
//                }
//            }
        }

        @Override
        public void onClick(View v) {
            ImageItemHolder holder = (ImageItemHolder) v.getTag(R.id.click_tag);
            if (holder.getAdapterPosition() == RecyclerView.NO_POSITION) {
                return;
            }
            final String path = mSubFiles[holder.getAdapterPosition()].getPath();
            if (TextUtils.isEmpty(path)) {
                Toast.makeText(getContext(), "文件不存在", Toast.LENGTH_SHORT).show();
                return;
            }
//            intent.putExtra(EXTRA_IMAGE_URL, Uri.fromFile(new File(path)));
//            setResult(RESULT_OK, intent);
//            finish();


            if (path.endsWith(".jpg")) {
                try {
                    Intent intent = new Intent();
                    intent.setAction(Intent.ACTION_VIEW);
                    intent.setDataAndType(Uri.fromFile(mSubFiles[holder.getAdapterPosition()]),
                            "image/*");
                    startActivity(intent);
                } catch (ActivityNotFoundException e) {
                    e.printStackTrace();
                }
            } else if (path.endsWith(".mp4")) {
                try {
                    Intent intent = new Intent();
                    intent.setAction(Intent.ACTION_VIEW);
                    intent.setDataAndType(Uri.fromFile(mSubFiles[holder.getAdapterPosition()]), "video/*");
                    startActivity(intent);
                } catch (ActivityNotFoundException e) {
                    e.printStackTrace();
                }
            }
        }

        class ImageItemHolder extends RecyclerView.ViewHolder {
            public final CheckBox mCheckBox;
            public final ImageView mImage;

            public ImageItemHolder(ImagePickerItemBinding binding) {
                super(binding.getRoot());
                mCheckBox = binding.imageCheckbox;
                mImage = binding.imageIcon;
                mImage.setOnClickListener(LocalFileFragment.this);
            }
        }
    }
}
