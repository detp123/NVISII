#pragma once

#include <mutex>
#include <condition_variable>

#include <visii/utilities/static_factory.h>
#include <visii/camera_struct.h>

/**
 * The "Camera" component describes the perspective of an entity.
 * It lens properties, like depth of field, focal length, field of view, and so on.
 * It also describes the target render resolution.
 * By connecting a camera component to an entity with a transform, that entity
 * can be used to render the scene from a position in space.
*/
class Camera : public StaticFactory
{
	friend class StaticFactory;
    // friend class Scene;
  public:
	/* Creates a camera, which can be used to capture the scene. */
	
	/** Constructs a camera component from a field of view.
	  *	The field of view controls the amount of zoom, i.e. the amount of the scene 
	  * which is visible all at once. A smaller field of view results in a longer focal length (more zoom),
	  * while larger field of view allow you to see more of the scene at once (shorter focal length, less zoom)
	  * 
	  * \returns a reference to a camera component
      * \param name A unique name for this camera.
      * \param field_of_view Specifies the field of view angle in the y direction. Expressed in radians.
	  * \param aspect Specifies the aspect ratio that determines the field of view in the x direction. The aspect ratio is a ratio of x (width) to y (height)
	  * \param near Specifies the distance from the viewer to the near clipping plane (always positive) */
	static Camera *createPerspectiveFromFOV(std::string name, float field_of_view, float aspect, float near);

	/** Constructs a camera component from a focal length.
	  * The focal length controls the amount of zoom, i.e. the amount of the scene 
	  * which is visible all at once. Longer focal lengths result in a smaller field of view (more zoom),
	  * while short focal lengths allow you to see more of the scene at once (larger FOV, less zoom)
	  * 
	  * \returns a reference to a camera component
      * \param name A unique name for this camera.
      * \param focal_length Specifies the focal length of the camera lens (in millimeters).
      * \param sensor_width Specifies the width of the camera sensor (in millimeters). 
	  * \param sensor_height Specifies the height of the camera sensor (in millimeters). 
	  * \param near Specifies the distance from the viewer to the near clipping plane (always positive) */
	static Camera *createPerspectiveFromFocalLength(std::string name, float focal_length, float sensor_width, float sensor_height, float near);

	/** Gets a Camera by name 
     * \return a Camera who's primary name key matches \p name */
	static Camera *get(std::string name);

	/** Gets a Camera by id 
     * \return a Camera who's primary id key matches \p id */
	static Camera *get(uint32_t id);

	/** \return a pointer to the table of CameraStructs */
	static CameraStruct *getFrontStruct();

	/** \returns a pointer to the list of camera components. */
	static Camera *getFront();

	/** \returns the total number of reserved cameras. */
	static uint32_t getCount();

	/** Deallocates a camera with the given name. */
	static void remove(std::string name);

	/** Deallocates a camera with the given id. */
	static void remove(uint32_t id);

	/** Allocates the tables used to store all Camera components */
	static void initializeFactory();

	/** \return True if the tables used to store all Camera components have been allocated, and False otherwise */
	static bool isFactoryInitialized();

	/** \return True the current camera is a valid, initialized camera, and False if the camera was cleared or removed. */
	bool isInitialized();

	/** Iterates through all components, updating any component struct fields and marking components as clean. */
    static void updateComponents();

	/* Releases vulkan resources */
	static void cleanUp();

    /** \return True if the material has been modified since the previous frame, and False otherwise */
    bool isDirty() { return dirty; }

	static bool areAnyDirty();

    /** \return True if the material has not been modified since the previous frame, and False otherwise */
    bool isClean() { return !dirty; }

    /** Tags the current component as being modified since the previous frame. */
    void markDirty();

    /** Tags the current component as being unmodified since the previous frame. */
    void markClean() { dirty = false; }

	static std::shared_ptr<std::mutex> getEditMutex();

    /** Returns a json string representation of the current component */
    std::string toString();

	// // /* Transfers all camera components to an SSBO */
	// // static void UploadSSBO(vk::CommandBuffer command_buffer);

	// /* Returns the SSBO vulkan buffer handle */
	// // static vk::Buffer GetSSBO();

	// /* Returns the size in bytes of the current camera SSBO. */
	// // static uint32_t GetSSBOSize();


	// /* Constructs an orthographic projection for the given multiview. */
	// // bool set_orthographic_projection(float left, float right, float bottom, float top, float near_pos, uint32_t multiview = 0);

	// /* Constructs a reverse Z perspective projection for the given multiview. */
	// void setPerspectiveProjection(float fov_in_radians, float width, float height, float near_pos, uint32_t multiview = 0);

	void usePerspectiveFromFOV(float field_of_view, float aspect, float near);

	void usePerspectiveFromFocalLength(float focal_length, float sensor_width, float sensor_height, float near);

	// /* Uses an external projection matrix for the given multiview. 
	// 	Note, the projection must be a reversed Z projection. */
	// void setCustomProjection(glm::mat4 custom_projection, float near_pos, uint32_t multiview = 0);

	// /* Returns the near position of the given multiview */
	// float getNearPos(uint32_t multiview = 0);

	/** \returns the entity transform to camera matrix.
		This additional transform is applied on top of an entity transform during rendering
		to see a particular "view". */
	glm::mat4 getView();

	// /* Sets the entity transform to camera matrix for the given multiview. 
	// 	This additional transform is applied on top of an entity transform during a renderpass
	// 	to see a particular "view". */

	void setView(glm::mat4 view);

	void setFocalDistance(float distance);

	void setApertureDiameter(float diameter);
	
	/** \returns the camera to projection matrix.
		This transform can be used to achieve perspective (eg a vanishing point), or for scaling
		an orthographic view. */
	glm::mat4 getProjection();

	// // /* Returns the texture component being rendered to. 
	// // 	Otherwise, returns None/nullptr. */
	// // Texture *get_texture();

	// // /* TODO: Explain this */
	// // uint32_t get_max_views();

	// /* Returns a json string summarizing the camera. */
	// std::string toString();

	// /* Sets the clear color to be used to reset the color image of this camera's
	// 	texture component when beginning a renderpass. */
	// void setClearColor(float r, float g, float b, float a);

	// /* Sets the clear stencil to be used to reset the depth/stencil image of this 
	// 	camera's texture component when beginning a renderpass. */
	// // void set_clear_stencil(uint32_t stencil);

	// /* Sets the clear depth to be used to reset the depth/stencil image of this 
	// 	camera's texture component when beginning a renderpass. Note: If reverse Z projections are used, 
	// 	this should always be 1.0 */
	// // void set_clear_depth(float depth);

	// /* Sets the renderpass order of the current camera. This is used to handle dependencies between 
	// 	renderpasses. Eg, rendering shadow maps or reflections. */
	// // void set_render_order(int32_t order);

	// void setMaxVisibleDistance(float max_distance);

	// float getMaxVisibleDistance();
	
	// /* Gets the renderpass order of the current camera. This is used to handle dependencies between 
	// 	renderpasses. Eg, rendering shadow maps or reflections. */
	// // int32_t get_render_order();

	// /* Returns the minimum render order set in the camera list */
	// // static int32_t GetMinRenderOrder();
	
	// /* Returns the maximum render order set in the camera list */
	// // static int32_t GetMaxRenderOrder();

	// /* TODO: Explain this */
	// // void force_render_mode(RenderMode rendermode);

	// /* TODO: Explain this */
	// // RenderMode get_rendermode_override();

	// /* TODO: Explain this */
	// // bool should_record_depth_prepass();

	// /* TODO: Explain this */
	// // bool should_use_multiview();

	// /* TODO: */
	// // void pause_visibility_testing();
	
	// /* TODO: */
	// // void resume_visibility_testing();

	// // void mark_render_as_complete();

	// // void wait_for_render_complete();

  private:
  	/* Creates an uninitialized camera. Useful for preallocation. */
	Camera();

	/* Creates a camera with the given name and id. */
	Camera(std::string name, uint32_t id);

  	/* TODO */
	static std::shared_ptr<std::mutex> editMutex;

	/* TODO */
	static bool factoryInitialized;
	
    /* A list of the camera components, allocated statically */
	static Camera cameras[MAX_CAMERAS];
	static CameraStruct cameraStructs[MAX_CAMERAS];
	
	/* A lookup table of name to camera id */
	static std::map<std::string, uint32_t> lookupTable;

    /* Indicates that one of the components has been edited */
    static bool anyDirty;

    /* Indicates this component has been edited */
    bool dirty = true;

	/* Determines whether this camera should use a depth prepass to reduce fragment complexity at the cost of 
	vertex shader complexity */
	// bool use_depth_prepass;

	/* TODO */
	// bool use_multiview;

	/* Marks the total number of multiviews being used by the current camera. */
	// uint32_t usedViews = 1;

	/* Marks the maximum number of views this camera can support, which can be possibly less than MAX_MULTIVIEW. */
	// uint32_t maxViews = MAX_MULTIVIEW;

	/* Marks when this camera should render during a frame. */
	// int32_t renderOrder = 0;

	/* Marks the range of render orders, so that the render system can create the right number of semaphores. */
	// static int32_t minRenderOrder;
	// static int32_t maxRenderOrder;

	/* A struct containing all data to be uploaded to the GPU via an SSBO. */
	// CameraStruct camera_struct;

	/* TODO: */
	// bool queryRecorded = false;

	// bool queryDownloaded = true;

	// bool visibilityTestingPaused = false;

	// uint64_t max_queried = 0;

	// float maxVisibilityDistance;

	// std::vector<std::vector<VisibleEntityInfo>> frustum_culling_results;

	/* The texture component attached to the framebuffer, which will be rendered to. */
	// Texture *renderTexture = nullptr;
	
	/* If msaa_samples is more than one, this texture component is used to resolve MSAA samples. */
	// Texture *resolveTexture = nullptr;
	
	/* The RGBA color used when clearing the color attachment at the beginning of a renderpass. */
	// glm::vec4 clearColor = glm::vec4(0.0);
	
	/* The depth value used when clearing the depth/stencil attachment at the beginning of a renderpass. */
	// float clearDepth = 0.0f;
	
	/* The stencil value used when clearing the depth/stencil attachment at the beginning of a renderpass. */
	// uint32_t clearStencil = 0;
	
	/* An integer representation of the number of MSAA samples to take when rendering. Must be a power of 2.
		if 1, it's inferred that a resolve texture is not required.  */
	// uint32_t samplesPerPixel = 1;

	// bool render_ready = false;
	// std::shared_ptr<std::mutex> render_complete_mutex;
	// std::shared_ptr<std::condition_variable> cv;
	
	/* A pointer to the mapped camera SSBO. This memory is shared between the GPU and CPU. */
	// static CameraStruct *pinnedMemory;
	
	/* A vulkan buffer handle corresponding to the material SSBO */
	// static vk::Buffer SSBO;
	
	/* The corresponding material SSBO memory. */
	// static vk::DeviceMemory SSBOMemory;

	/* TODO */
	// static vk::Buffer stagingSSBO;
	
	/* TODO */
	// static vk::DeviceMemory stagingSSBOMemory;

	// RenderMode renderModeOverride;

	/* Allocates (and possibly frees existing) textures, renderpass, and framebuffer required for rendering. */
	// void setup(uint32_t tex_width = 0, uint32_t tex_height = 0, uint32_t msaa_samples = 1, uint32_t max_views = 1, bool use_depth_prepass = true, bool use_multiview = false);

	/* Updates the usedViews field to account for a new multiview. This is fixed to the allocated texture layers 
		when recording is enabled. */
	// void update_used_views(uint32_t multiview);

	/* Checks to see if a given multiview index is within the multiview bounds, bounded either by MAX_MULTIVIEW, or the 
		camera's texture layers */
	// void check_multiview_index(uint32_t multiview);

	/* Releases any vulkan resources. */
	// void cleanup();
};