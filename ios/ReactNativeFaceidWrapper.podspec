
Pod::Spec.new do |s|
  s.name         = "ReactNativeFaceIDWrapper"
  s.version      = "1.0.0"
  s.summary      = "ReactNativeFaceIDWrapper"
  s.description  = <<-DESC
                  ReactNativeFaceIDWrapper
                   DESC
  s.homepage     = "https://github.com/xupea"
  s.license      = "MIT"
  # s.license      = { :type => "MIT", :file => "FILE_LICENSE" }
  s.author             = { "author" => "author@domain.cn" }
  s.platform     = :ios, "7.0"
  s.source       = { :git => "https://github.com/xupea/react-native-faceid-wrapper.git", :tag => "master" }
  s.source_files  = "ReactNativeFaceIDWrapper/**/*.{h,m}"
  s.requires_arc = true


  s.dependency "React"
  #s.dependency "others"

end

  