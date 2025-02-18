// Copyright (c) Microsoft Corporation.
// Licensed under the MIT License.
#pragma once
#include "PackageManager.g.h"

namespace winrt::Microsoft::Management::Deployment::implementation
{
#if USE_PROD_CLSIDS 
    [uuid("C53A4F16-787E-42A4-B304-29EFFB4BF597")]
#else
    [uuid("74CB3139-B7C5-4B9E-9388-E6616DEA288C")]
#endif
    struct PackageManager : PackageManagerT<PackageManager>
    {
        PackageManager() = default;

        winrt::Windows::Foundation::Collections::IVectorView<winrt::Microsoft::Management::Deployment::PackageCatalogReference> GetPackageCatalogs();
        winrt::Microsoft::Management::Deployment::PackageCatalogReference GetPredefinedPackageCatalog(winrt::Microsoft::Management::Deployment::PredefinedPackageCatalog const& predefinedPackageCatalog);
        winrt::Microsoft::Management::Deployment::PackageCatalogReference GetLocalPackageCatalog(winrt::Microsoft::Management::Deployment::LocalPackageCatalog const& localPackageCatalog);
        winrt::Microsoft::Management::Deployment::PackageCatalogReference GetPackageCatalogByName(hstring const& catalogName);
        winrt::Microsoft::Management::Deployment::PackageCatalogReference CreateCompositePackageCatalog(winrt::Microsoft::Management::Deployment::CreateCompositePackageCatalogOptions const& options);
        winrt::Windows::Foundation::IAsyncOperationWithProgress<winrt::Microsoft::Management::Deployment::InstallResult, winrt::Microsoft::Management::Deployment::InstallProgress> 
            InstallPackageAsync(winrt::Microsoft::Management::Deployment::CatalogPackage package, winrt::Microsoft::Management::Deployment::InstallOptions options);
        // Contract 2.0
        winrt::Windows::Foundation::IAsyncOperationWithProgress<winrt::Microsoft::Management::Deployment::InstallResult, winrt::Microsoft::Management::Deployment::InstallProgress> 
            GetInstallProgress(winrt::Microsoft::Management::Deployment::CatalogPackage package, winrt::Microsoft::Management::Deployment::PackageCatalogInfo catalogInfo);
        // Contract 4.0
        winrt::Windows::Foundation::IAsyncOperationWithProgress<winrt::Microsoft::Management::Deployment::InstallResult, winrt::Microsoft::Management::Deployment::InstallProgress>
            UpgradePackageAsync(winrt::Microsoft::Management::Deployment::CatalogPackage package, winrt::Microsoft::Management::Deployment::InstallOptions options);
        winrt::Windows::Foundation::IAsyncOperationWithProgress<winrt::Microsoft::Management::Deployment::UninstallResult, winrt::Microsoft::Management::Deployment::UninstallProgress>
            UninstallPackageAsync(winrt::Microsoft::Management::Deployment::CatalogPackage package, winrt::Microsoft::Management::Deployment::UninstallOptions options);
        winrt::Windows::Foundation::IAsyncOperationWithProgress<winrt::Microsoft::Management::Deployment::UninstallResult, winrt::Microsoft::Management::Deployment::UninstallProgress>
            GetUninstallProgress(winrt::Microsoft::Management::Deployment::CatalogPackage package, winrt::Microsoft::Management::Deployment::PackageCatalogInfo catalogInfo);
    };
}

#if !defined(INCLUDE_ONLY_INTERFACE_METHODS)
namespace winrt::Microsoft::Management::Deployment::factory_implementation
{
    struct PackageManager : PackageManagerT<PackageManager, implementation::PackageManager>
    {
    };
}
#endif
