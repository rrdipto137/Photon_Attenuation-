#include "DetectorConstruction.hh"
#include "G4Tubs.hh"
#include "G4RunManager.hh"
#include "G4NistManager.hh"
#include "G4Box.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"

namespace photon_dose_sim
{
    G4VPhysicalVolume* DetectorConstruction::Construct()
    {
         G4NistManager* nist = G4NistManager::Instance();

        // world properties
        G4Material* worldMaterial = nist->FindOrBuildMaterial("G4_Galactic");
        G4bool checkOverlaps = false;

        G4int worldSizeX = 50*cm;
        G4int worldSizeY = 50*cm;
        G4int worldSizeZ = 50*cm;


        // define worlds
        auto solidWorld = new G4Box("World",
            worldSizeX,                 // default is mm (it seems like)
            worldSizeY,
            worldSizeZ);

        auto logicWorld = new G4LogicalVolume(solidWorld,
            worldMaterial, "World");

        auto physWorld = new G4PVPlacement(nullptr,  // no rotation
            G4ThreeVector(),                           // at (0,0,0)
            logicWorld,                                // its logical volume
            "World",                                   // its name
            nullptr,                                   // its mother  volume
            false,                                     // no boolean operation
            0,                                         // copy number
            checkOverlaps);                            // overlaps checking

        
        

   // Source
        
        
  /*      G4Material* sourceMaterial = nist->FindOrBuildMaterial("G4_AIR"); // Example material, change as needed
        G4double sourceInnerRadius = 0 * cm;
        G4double sourceOuterRadius = 10 * cm;
        G4double sourceHeightX = 5 * cm;
        G4double sourcethetaStart = 0 * deg;
        G4double sourcethetaDelta = 360 * deg;
        G4ThreeVector sourcePosition = G4ThreeVector(0, 0, -40 * cm); // Adjust position as needed
        
     
     
        G4RotationMatrix* rotation = new G4RotationMatrix();
        rotation->rotateX(90 * deg); // Rotate around X axis by 90 degrees

     
     
        auto solidSource = new G4Tubs("Source",
                                       sourceInnerRadius,
                                       sourceOuterRadius,
                                       sourceHeightX,
                                       sourcethetaStart,
                                       sourcethetaDelta
                                     );

        auto logicSource = new G4LogicalVolume(solidSource,
                                               sourceMaterial,
                                               "Source");

        new G4PVPlacement(rotation,    //  90 degree rotation in X axis 
                           sourcePosition,              // position
                           logicSource,                 // its logical volume
                           "Source",                    // its name
                           logicWorld,                  // its mother  volume
                           false,                       // no boolean operation
                           0,                           // copy number
                           checkOverlaps);              // overlaps checking
                           
                           
                           
                         
               */            

       // First Detector
     G4Material*detector1Material = nist->FindOrBuildMaterial("G4_SODIUM_IODIDE");
        G4double detector1SizeX = 0.4 ;
        G4double detector1SizeY = 0.4 ;
        G4double detector1SizeZ = 0.4 * cm;
        G4ThreeVector detector1Pos = G4ThreeVector(0, 0, -5 * cm);

        auto solidDetector1 = new G4Box("Detector1",
            detector1SizeX,
            detector1SizeY,
            detector1SizeZ);

        auto logicDetector1 = new G4LogicalVolume(solidDetector1,
            detector1Material,
            "Detector1");

        new G4PVPlacement(nullptr,    // rotation
            detector1Pos,              // position
            logicDetector1,           // its logical volume
            "Detector1",              // its name
            logicWorld,               // its mother  volume
            false,                    // boolean operation
            0,                        // copy number
            checkOverlaps);           // overlaps checking

      
      
      
         //Shield of polyboron
  
  /*
G4double polyboronDensity = 0.971 * g/cm3;
G4Material* polyboronMaterial = new G4Material("Polyboron", polyboronDensity, 4);

polyboronMaterial->AddElement(nist->FindOrBuildElement("H"), 12.38 * perCent);
polyboronMaterial->AddElement(nist->FindOrBuildElement("B"), 4.89 * perCent);
polyboronMaterial->AddElement(nist->FindOrBuildElement("C"), 59.88 * perCent);
polyboronMaterial->AddElement(nist->FindOrBuildElement("O"), 22.85 * perCent);

G4double leadSizeX = worldSizeX;
G4double leadSizeY = worldSizeY;
G4double leadSizeZ = 0.1 * cm; // Adjust the thickness of the lead shield as needed

auto solidLead = new G4Box("LeadShield",
    leadSizeX,
    leadSizeY,
    leadSizeZ);

auto logicLead = new G4LogicalVolume(solidLead,
    polyboronMaterial,
    "LeadShield");

G4ThreeVector leadPos = G4ThreeVector(0, 0, 22.5 * cm); // Position lead shield between the detectors
new G4PVPlacement(nullptr,
    leadPos,
    logicLead,
    "LeadShield",
    logicWorld,
    false,
    0,
    checkOverlaps);

      */
      
      

//ordinary concrete 
 /*
G4double polyboronDensity = 2.35* g/cm3;
G4Material* polyboronMaterial = new G4Material("Polyboron", polyboronDensity, 10);

polyboronMaterial->AddElement(nist->FindOrBuildElement("H"), 0.56 * perCent);
polyboronMaterial->AddElement(nist->FindOrBuildElement("Fe"),1.22 * perCent);
polyboronMaterial->AddElement(nist->FindOrBuildElement("Ca"), 8.26 * perCent);
polyboronMaterial->AddElement(nist->FindOrBuildElement("O"), 49.56 * perCent);
polyboronMaterial->AddElement(nist->FindOrBuildElement("Na"), 1.71 * perCent);
polyboronMaterial->AddElement(nist->FindOrBuildElement("Mg"), 0.24 * perCent);
polyboronMaterial->AddElement(nist->FindOrBuildElement("Al"), 4.56 * perCent);
polyboronMaterial->AddElement(nist->FindOrBuildElement("Si"), 31.35 * perCent);
polyboronMaterial->AddElement(nist->FindOrBuildElement("S"), 0.12 * perCent);
polyboronMaterial->AddElement(nist->FindOrBuildElement("K"), 1.92 * perCent);

G4double leadSizeX = worldSizeX;
G4double leadSizeY = worldSizeY;
G4double leadSizeZ = 4* cm; // Adjust the thickness of the lead shield as needed

auto solidLead = new G4Box("LeadShield",
    leadSizeX,
    leadSizeY,
    leadSizeZ);

auto logicLead = new G4LogicalVolume(solidLead,
    polyboronMaterial,
    "LeadShield");

G4ThreeVector leadPos = G4ThreeVector(0, 0, 22.5 * cm); // Position lead shield between the detectors
new G4PVPlacement(nullptr,
    leadPos,
    logicLead,
    "LeadShield",
    logicWorld,
    false,
    0,
    checkOverlaps);
       
        
        
   */
        
        
        /*
G4double polyboronDensity = 1.19* g/cm3;
G4Material* polyboronMaterial = new G4Material("Polyboron", polyboronDensity, 6);

polyboronMaterial->AddElement(nist->FindOrBuildElement("H"), 8.76 * perCent);
polyboronMaterial->AddElement(nist->FindOrBuildElement("B"),30.0 * perCent);
polyboronMaterial->AddElement(nist->FindOrBuildElement("C"), 60.60 * perCent);
polyboronMaterial->AddElement(nist->FindOrBuildElement("O"), 0.02 * perCent);
polyboronMaterial->AddElement(nist->FindOrBuildElement("Si"), 0.04 * perCent);
polyboronMaterial->AddElement(nist->FindOrBuildElement("Fe"), 0.04 * perCent);

G4double leadSizeX = worldSizeX;
G4double leadSizeY = worldSizeY;
G4double leadSizeZ = 4* cm; // Adjust the thickness of the lead shield as needed

auto solidLead = new G4Box("LeadShield",
    leadSizeX,
    leadSizeY,
    leadSizeZ);

auto logicLead = new G4LogicalVolume(solidLead,
    polyboronMaterial,
    "LeadShield");

G4ThreeVector leadPos = G4ThreeVector(0, 0, 22.5 * cm); // Position lead shield between the detectors
new G4PVPlacement(nullptr,
    leadPos,
    logicLead,
    "LeadShield",
    logicWorld,
    false,
    0,
    checkOverlaps);
       
        
        */
    
    /*    
G4double polyboronDensity = 1.19* g/cm3;
G4Material* polyboronMaterial = new G4Material("Polyboron", polyboronDensity, 2);

polyboronMaterial->AddElement(nist->FindOrBuildElement("H"), 11.9 * perCent);
polyboronMaterial->AddElement(nist->FindOrBuildElement("O"),88.1 * perCent);


G4double leadSizeX = worldSizeX;
G4double leadSizeY = worldSizeY;
G4double leadSizeZ = 4* cm; // Adjust the thickness of the lead shield as needed

auto solidLead = new G4Box("LeadShield",
    leadSizeX,
    leadSizeY,
    leadSizeZ);

auto logicLead = new G4LogicalVolume(solidLead,
    polyboronMaterial,
    "LeadShield");

G4ThreeVector leadPos = G4ThreeVector(0, 0, 22.5 * cm); // Position lead shield between the detectors
new G4PVPlacement(nullptr,
    leadPos,
    logicLead,
    "LeadShield",
    logicWorld,
    false,
    0,
    checkOverlaps);
       */
   
   
   
   //polythene    
   
 
    /*
       G4double polyboronDensity = 0.92* g/cm3;
G4Material* polyboronMaterial = new G4Material("Polyboron", polyboronDensity, 2);

polyboronMaterial->AddElement(nist->FindOrBuildElement("H"), 14.37 * perCent);
polyboronMaterial->AddElement(nist->FindOrBuildElement("B"),85.63 * perCent);

G4double leadSizeX = worldSizeX;
G4double leadSizeY = worldSizeY;
G4double leadSizeZ = 4* cm; // Adjust the thickness of the lead shield as needed

auto solidLead = new G4Box("LeadShield",
    leadSizeX,
    leadSizeY,
    leadSizeZ);

auto logicLead = new G4LogicalVolume(solidLead,
    polyboronMaterial,
    "LeadShield");

G4ThreeVector leadPos = G4ThreeVector(0, 0, 22.5 * cm); // Position lead shield between the detectors
new G4PVPlacement(nullptr,
    leadPos,
    logicLead,
    "LeadShield",
    logicWorld,
    false,
    0,
    checkOverlaps);
        
        
        
        */
        
        
        
        
        
        
        
        
        // Second Detector (45 cm apart)
        G4Material*detector2Material = nist->FindOrBuildMaterial("G4_SODIUM_IODIDE");
        G4double detector2SizeX = 10*cm ;
        G4double detector2SizeY = 10*cm;
        G4double detector2SizeZ = 10 * cm;
        G4ThreeVector detector2Pos2 = G4ThreeVector(0, 0, 50 * cm); // 50 cm apart in the z-direction

        auto solidDetector2 = new G4Box("Detector2",
            detector2SizeX,
            detector2SizeY,
            detector2SizeZ);

        auto logicDetector2 = new G4LogicalVolume(solidDetector2,
            detector2Material,
            "Detector2");

        new G4PVPlacement(nullptr,    // rotation
            detector2Pos2,             // position
            logicDetector2,           // its logical volume
            "Detector2",              // its name
            logicWorld,               // its mother  volume
            false,                    // boolean operation
            1,                        // copy number (different than the first detector)
            checkOverlaps);           // overlaps checking

        

        // Set scoring volumes
        fScoringVolume1= logicDetector2;
         fScoringVolume2= logicDetector1;
        
       
        return physWorld;
    }
}

